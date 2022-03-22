/*Megan Da Costa*/
/*CS3305 - Assignment 2*/
/*Due: October 8th 2021*/
/*practicing with pipes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char **argv)
{
    pid_t pid;
    int p, c;
    int Xlen;
    int port[2];
    char rd[50];

    /*creates pipe and stores its numerical value in status*/
    pipe(port);

    /*if the pipe creation is unsuccessful, raises an error*/
    if(pipe(port) < 0)
    {
        perror("pipe() unsuccessful\n");
        exit(0);
    }
    
    pid = fork();

    /*error message if fork fails*/
	if(pid < 0)
	{
		perror("fork() unsuccessful\n");
        exit(0);
	}

    /*parent process*/
    if(pid > 0)
    {
        p = getpid(); //holds parent pid

        printf("parent (PID %d) created a child (PID %d)\n", p, pid);

        char * X = argv[1]; //character pointer X holds the first command line argument
        Xlen = strlen(X) + 1;

        printf("parent (PID %d) receives X = \"%s\" from the user\n", p, X);

        printf("parent (PID %d) writes X = \"%s\" to the pipe\n", p, X);
        write(port[1], X, Xlen); //writes string pointed to by X into the pipe

        wait(NULL); //parent will wait for child to complete before continuing

        read(port[0], rd, 50); //after returning from child the parent will read what is in the pipe into the charcter array rd
        printf("parent (PID %d) reads concatenated result from the pipe (Z' = \"%s\")\n", p, rd);
    }

    /*child process*/
    if(pid == 0)
    {
        read(port[0], rd, 0); //forces the parent to execute its first few lines while pipe is empty

        p = getppid();
        c = getpid();

        char * Y = argv[2]; //character pointer Y holds the second command line argument
        char * Z = argv[3]; //character pointer Z holds the third command line argument
        printf("child (PID %d) receives Y = \"%s\" and Z = \"%s\" from the user\n", c, Y, Z);

        int Yplen = strlen(Y) + strlen(Z) + 1; //Yplen holds the length of what will be Y' string (with space for null termination)
        char temp[Yplen]; //a temporary array is made to hold the string
        strcat(strcat(strcpy(temp, Y), " "), Z); //temp array holds string from Y, adds a space behind it, then concatenates it with the string from Z
        printf("child (PID %d) concatenates Y and Z to generate Y' = \"%s\"\n", c, temp);

        int Zplen = Xlen + Yplen + 2; //Zplen holds the length of what will be Z' string
        char temp2[Zplen]; //a larger temporary array is mad eto hold the final string
        read(port[0], temp2, Zplen); //the string put into the pipe (in parent) is read and stored in temp2 array
        printf("child (PID %d) reads X from pipe = \"%s\"\n", c, temp2);

        strcat(strcat(temp2, " "), temp); //temp2 array (with a space in it) is concatenated with temp array to give Z'
        printf("child (PID %d) concatenates X and Y' to generate Z' = \"%s\"\n", c, temp2);

        write(port[1], temp2, Zplen + 1); //the fully concatenated string in temp2 is written into the pipe
        printf("child (PID %d) writes Z' into the pipe\n", c);
    }

    return(0);
}
