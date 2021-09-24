/*CS3305 Assignment 1*/
/*Due: September 27 2021*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
    /*create int holders for PIDs and character array*/
    pid_t pid1, pid2, pid2_1;
    int p, c;
    char pchar[100];
    
    /*parent makes child 1*/
    pid1 = fork(); 

    /*error message if fork fails*/
    if(pid1 < 0)
    {
        perror("fork() unsuccessful");
    }

    /*parent process that will make child_2 and subsequently child_2.1*/
    if(pid1 > 0)
    {
        /*parent will wait for child_1 to complete before continuing*/
        wait(NULL);

        /*child 2 s created*/
        pid2 = fork();

        /*error message if second fork fails*/
        if (pid2 < 0)
        {
            perror("fork() unsuccessful");
        }

        /*child_2 which is parent of child_2.1 process*/
        if (pid2 > 0)
        {
        /*parent will wait for child 2 to complete*/
        wait(NULL); 

        printf("child_1 and child_2 are completed and parent process is terminating...\n");
        }

        if (pid2 == 0)
        {
            p = getppid(); //p holds parent pid
            c = getpid(); //c holds child_2 pid
            printf("parent (PID %d) created child_2 (PID %d)\n", p, c);

            /*child_2 creates child_2.1*/
            pid2_1 = fork();

            /*error message is fork 2.1 fails*/
            if (pid2_1 < 0)
            {
                perror("fork() unsuccessful");
            }

            /*child_2 which is parent of child_2.1 process*/
            if (pid2_1 > 0)
            {
                wait(NULL);
            }

            /*child_2.1 process*/
            if(pid2_1 == 0)
            {
                p = getppid(); //p holds child_2 pid
                c = getpid(); //c holds child_2.1 pid
                printf("child_2 (PID %d) created child_2.1 (PID %d)\n", p, c);

                printf("child_2.1 (PID %d) is calling an external program, external_program.out, and leaving child_2\n",c);

                sprintf(pchar, "%d", c);
                strcat(pchar, " for child_2.1");
                execl("external_program.out", argv[1], pchar, NULL);
            }
        }

    }

    /*child_1 process*/
    if (pid1 == 0)
    {
        p = getppid(); //p holds parent pid
        c = getpid(); //c holds child_1 pid
        printf("parent (PID %d) created child_1 (PID %d)\n", p, c);
        printf("parent (PID %d) is waiting for child_1 (PID %d) to complete before creating child_2\n", p, c);

        printf("child_1 (PID %d) is calling an external program, external_program.out, and leaving parent\n",c);

        sprintf(pchar, "%d", c);
        strcat(pchar, " for child_1");
        execl("external_program.out", argv[1], pchar, NULL);
    }

    return(0);
}
