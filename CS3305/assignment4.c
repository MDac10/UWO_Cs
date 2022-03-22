/*Megan Da Costa*/
/*CS3305 - Assignment 4*/
/*Due: November 8th 2021*/
/*practicing with CPU scheduling - round robin*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*Process structure holds all information about a single process (number, arrival time, burst time, waiting time, and turnaround time*/
typedef struct Process
{
    int p_id;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
}process;

/*processPrint reads through the input processes and looks at when each process is completed follwoing round robin cpu scheduling*/
int processPrint(process p[], int q, int len)
{
    process orglist[len];
    int i = 0, ptime = 0, flag = 1, checked;
    int tt = 0, wt = 0;

    for(int j = 0; j < len; j++) //makes a copy of the list of processes so that the original information does not get altered
    {
        orglist[j] = p[j];
    }

    while(flag == 1) //flag is set for the while loop to be initiated
    {
        checked = 1;
        for(i = 0; i < len; i++) //checking each process element in the process list
        {
            if(orglist[i].burst > 0) //if the burst time is greater than 0 then it still needs to be checked
            {
                checked = 0; //...therefore the checked value is set to false (0)

                if(orglist[i].burst <= q) //if the burst time is less than or equal to the quantum (q) value
                {
                    ptime +=orglist[i].burst; //the burst time for that process is added to the total alloted time for processes
                    p[i].waiting = (ptime - p[i].burst - p[i].arrival); //the waiting time can be calculated and stored in that process
                    wt +=p[i].waiting; //adds to total turnaround time
                    p[i].turnaround = (ptime - p[i].arrival); //the turnaround time can be calculated and stored in that process
                    tt +=p[i].turnaround; //adds to sum of all waiting times
                    orglist[i].burst = 0; //setting the processes burst time helps to escape the for loop and mark this process as checked
                }
                else //if the burst time is greater than the quantum (q) value
                {
                    ptime +=q; //the quantum value is added to the total alloted time for processes
                    orglist[i].burst -=q; //the burst time for that process is reduced by the quantum value and the loop continues until all processes have a burst time of 0 in the copied process list
                }
            }
        }

        if(checked == 1) //if the value checked is marked as true (1) then the flag is set to 0 and the while loop is escaped
        {
            flag = 0;
        }
    }

    printf("\n");
    for(int a = 0; a < len; a++)
    {
        printf("Process: P%d Arrival Time: %d Burst time: %d Waiting Time: %d Turnaround Time: %d\n", p[a].p_id, p[a].arrival, p[a].burst, p[a].waiting, p[a].turnaround);
    }
    printf("\nTotal Turnaround Time: %d\n", tt);
    printf("Average waiting time: %.2fs\n", ((float)wt/(float)len));
    printf("Average turnaround time: %.2fs\n", ((float)tt/(float)len));

    return(0);
}

int main(void)
{
    process plist[10];

    char line[50], readProc[50];
    FILE *input;

    input = fopen("rr_input.txt", "r"); //open input file with all process information

    while(fgets(line, 35, input) != NULL) //creates a loop to check each line of the file until EOF is reached
    {
        strcpy(readProc, line);
        int pcount = 0, i = 0, len = 0;

        while(readProc[i] != '\0') //checking until the end of a line
        {
            if(readProc[i] == 'p' || readProc[i] == 'P') //beginning of a processes information
            {
                process newProc; //creates a new process structure instance

                i++;
                char pidbuffer[3]; //holds the string for process id value (because it could be larger than one character)
                for(int j = 0; j < 3; j++)
                {
                    if(readProc[i] != ' ') //reads the sting until it encounters a space (the value before the space would be the process number)
                    {
                        pidbuffer[j] = readProc[i];
                        i++;
                    }
                    else{pidbuffer[j] = '\0';} //if a space is encountered the string will be ended with its null character '\0'
                }
                newProc.p_id = atoi(pidbuffer); //converts the value beside 'p' in the string to an integer (the process number) 
        
                i++;
                char arrivalbuffer[3]; //holds the string for the processes arrival time (because it could be larger than one character)
                for(int j = 0; j < 3; j++)
                {
                    if(readProc[i] != ' ') //reads the sting until it encounters a space (the value before the space would be the arrival time)
                    {
                        arrivalbuffer[j] = readProc[i];
                        i++;
                    }
                    else{arrivalbuffer[j] = '\0';} //if a space is encountered the string will be ended with its null character '\0'
                }
                newProc.arrival = atoi(arrivalbuffer); //converts the next value into an integer to be the arrival time for that process

                i++;
                char burstbuffer[3]; //holds the string for burst value (because it could be larger than one character)
                for(int j = 0; j < 3; j++)
                {
                    if(readProc[i] != ' ') //reads the sting until it encounters a space (the value before the space would be the burst time)
                    {
                        burstbuffer[j] = readProc[i];
                        i++;
                    }
                    else{burstbuffer[j] = '\0';} //if a space is encountered the string will be ended with its null character '\0'
                }
                newProc.burst = atoi(burstbuffer); //the string for the buffer is converted to a an integer and stored in the process structure

                plist[pcount] = newProc; //the process structure created is stored in the list of process structures
                pcount++;
                len++;
            }

            if(readProc[i] != ' ' && (readProc[i] != 'p' || readProc[i] != 'P')) //if the next value is not an indication of another process (p or P) and it is not a space then it must be the quantum value
            {
                int quantum = readProc[i] - '0'; //converts this value into an integer to be used as the quantum value
                processPrint(plist, quantum, len); //the processPrint function above is called for each list of process structs
                break;
            }

            i++;
        }
    }

    fclose(input);

    return(0);
}
