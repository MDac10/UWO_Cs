/*Megan Da Costa - Student ID: 251009855*/
/*CS3305 - Assignment 5*/
/*Due: November 29th 2021*/
/*bank account example - practicing mutual exclusion*/
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

/*Process structure holds all information about a single process (number, arrival time, burst time, waiting time, and turnaround time*/
typedef struct Account
{
    char a_id;
    int balance;
    int withdrawnFromAcct[10];
    int withcount;
}account;

/*a list holding account structures will be usd as the global variables that all the clients have access to*/
account alist[20];
pthread_mutex_t lock;
char wacct[20], dacct[20];
int withdrawn[20], deposited[20];
int pos = 0, wpos = 0, dpos = 0, numOfAccts = 0;

void *requestWithdraw(void *acct)
{
    int *temp = (int *) acct;
    int wp = *temp; //allows reference to the input integer

    fflush(stdout);

    pthread_mutex_lock(&lock); /*Enters the critical section*/

    fflush(stdout);

    if(alist[pos].balance >= alist[pos].withdrawnFromAcct[wp]) //checks to see if the balance in the account is greater or equal than the withdraw request to see if the withdraw is possible
    {
        fflush(stdout);
        int newBal = alist[pos].balance;
        newBal = newBal - alist[pos].withdrawnFromAcct[wp];
        alist[pos].balance = newBal; //sets new balance after the withdraw
        fflush(stdout);
    } 
    else 
    {
        fflush(stdout);
        //indicates there are not enough funds for a withdraw request
    }

    /*End of critical section*/

    pthread_mutex_unlock(&lock);
}

/*Goes through every account in the account list and adds all deposits to that account balance*/
void parseanddeposit(account acct[])
{
    for(int j = 0; j < numOfAccts; j++)
    {
        int newbalance = acct[j].balance;
        for(int i = 0; i < dpos; i++)
        {
            if(acct[j].a_id == dacct[i]) //checks to see if the account numbers match
            {
                newbalance += deposited[i]; //updates account balance. Now includes deposit amount
            }
        }
        acct[j].balance = newbalance;
    }
}

/*sets the withdraw request values in each of the accounts in the account list*/
void parsewithdrawrequests(account acct[])
{
    for(int j = 0; j < numOfAccts; j++)
    {
        int numofw = 0;
        for(int i = 0; i < wpos; i++)
        {
            if(acct[j].a_id == wacct[i]) //checks to see if the account numbers match
            {
                acct[j].withdrawnFromAcct[numofw] = withdrawn[i]; //sets the withdraw request values in the account
                numofw++;
            }
        }
        acct[j].withcount = numofw; //each account keeps not of how many withdraw requests there are for later iterations through them
    }
}

int main(void)
{
    char line[50], readBank[50];
    FILE *input;

    input = fopen("assignment_6_input.txt", "r"); //open input file with all bank account and client information

    while(fgets(line, 50, input) != NULL) //creates a loop to check each line of the file until EOF is reached
    {
        strcpy(readBank, line);
        int  i = 0;

        while(readBank[i] != '\0') //checking until the end of a line
        {
            if(readBank[i] == 'a') //checks to see if the first character in line is an a indicating that it is an account
            {
                account newaccount; //makes a new account sturcture value
                i++;

                newaccount.a_id = readBank[i]; //holds the account number as a character in the newaccount sturcture

                i+=4;

                char balancebuffer[10]; //Gets the balance money value
                for(int j = 0; j < 10; j++)
                {
                    if(readBank[i] != ' ') //takes every value as part of the balance until a space is reached
                    {
                        balancebuffer[j] = readBank[i];
                        i++;
                    }
                    else{balancebuffer[j] = '\0'; break;} 
                }
                newaccount.balance = atoi(balancebuffer); //stores balance in the account structure

                alist[numOfAccts] = newaccount; //puts new account into the list of accounts
                numOfAccts++;
            }

            if(readBank[i] == 'c') //indicates a new client is being read in
            {
               i+=3;

               while(readBank[i] != '\0')
               {
                   if(readBank[i] == 'd') //indicated that the client wants to deposit money into an account
                   {
                       i+=3;
                       dacct[dpos] = readBank[i]; //holds account id where the money is to be deposited
                       i+=2;
                       char depositbuffer[10]; //Get money deposited value
                       for(int j = 0; j < 10; j++)
                       {
                           if(readBank[i] != ' ') 
                           {
                               depositbuffer[j] = readBank[i];
                               i++;
                           }
                           else{depositbuffer[j] = '\0'; break;} 
                       }
                       deposited[dpos] = atoi(depositbuffer); //holds the amount that is to be deposited into the given account

                       dpos++;
                    }

                    if(readBank[i] == 'w') //indicates tat the client is requesting to withdraw money form am account
                    {
                        i+=3;
                        wacct[wpos] = readBank[i]; //holds the account is that the client wants to withdraw from

                        i+=2;
                        char withdrawbuffer[10]; //Get money withdrawn value
                        for(int j = 0; j < 10; j++)
                        {
                            if(readBank[i] != ' ') 
                            {
                                withdrawbuffer[j] = readBank[i];
                                i++;
                            }
                            else{withdrawbuffer[j] = '\0';} 
                        }
                        withdrawn[wpos] = atoi(withdrawbuffer); //holds the amount that the client wants to withdraw from the given account

                        wpos++;
                    }
                    i++;
                }

            }

            i++;
        }

    }

    parseanddeposit(alist); //puts through all deposits into each of the ccounts
    parsewithdrawrequests(alist); //stores the withdraw amounts into their corresponding accounts (into the withdrawnFromAcct field)

    for(int j = 0; j < numOfAccts; j++) //iterates through each of the accounts in the account list
    {
        int tid[5];
        int t, err_thread;
        pthread_t withdrawthreads[alist[j].withcount]; //makes a list of threads to match the number of withdraws that are supposed to occur

        if (pthread_mutex_init(&lock, NULL) != 0)
        {
            printf("\n mutex init failed\n");
            return 1;
        }

        for(t = 0; t < alist[j].withcount; t++) //for ech of the withdraw requests...
        {
            tid[t] = t;
            err_thread = pthread_create(&withdrawthreads[t], NULL, &requestWithdraw, (void*)(tid + t)); //creates the thread for the withdraw request

            if (err_thread != 0)
            {
	            printf("\n Error creating thread %d", t);
            }
        }

        for(t = 0; t < alist[j].withcount; t++)
        {
            pthread_join(withdrawthreads[t], NULL);
        }

        printf("a%c b %d\n", alist[j].a_id, alist[j].balance); //shows the final balances in each of the accounts
        pos++;
    }

    return(0);
}