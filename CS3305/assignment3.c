/*Megan Da Costa - Student ID: 251009855*/
/*CS3305 - Assignment 3*/
/*Due: October 25th 2021*/
/*practicing with threads*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pid_t pid;
pthread_t t1, t2, t3;
int p, X, Y, S;
int rd[2];
int port[2];

/*sum reads the integers in the pipe, adds them together, and writes the sum to the pipe*/
void *sum(void *thread_id)
{
    read(port[0], rd, 8); //reads both ints from pipe
    printf("thread (TID %d) reads X = %d and Y = %d from the pipe\n", *(int *) thread_id, rd[0], rd[1]);
    int s = rd[0] + rd[1]; //sum of the pipe values
    printf("thread (TID %d) writes X + Y = %d to the pipe\n", *(int *) thread_id, s);
    write(port[1], &s, 4); //writes sum to pipe

}

/*odd_even reads the sum that was stored in the pipe by *sum, determines if it is odd or even an dthen writes it back to the pipe*/
void *odd_even(void *thread_id)
{
    read(port[0], &S, 4); //reads the sum from the pipe
    printf("thread (TID %d) reads X + Y = %d from the pipe\n", *(int *) thread_id, S);

    //modulo is used to determine if sum is even or odd
    if(S % 2 == 0) //if sum % 2 = 0 then sum is even
    {
        printf("thread (TID %d) identifies X + Y = %d as an even number\n", *(int *) thread_id, S);
    }
    else //if sum % 2 = 1 then sum is odd
    {
        printf("thread (TID %d) identifies X + Y = %d as an odd number\n", *(int *) thread_id, S);
    }

    printf("thread (TID %d) writes X + Y = %d to the pipe\n", *(int *) thread_id, S);
    write(port[1], &S, 4); //writes the sum back to pipe
}

/*digit_count reads the sum form the pipe and determines how many digits there are in it*/
void *digit_count(void *thread_id)
{
    read(port[0], &S, 4); //reads the sum value from the pipe
    printf("thread (TID %d) reads X + Y = %d from the pipe\n", *(int *) thread_id, S);
    
    int digit = S; //stores the sum value so that it won't change for the next printf line
    int count = 0; //used to count each consecutive digit

    while(digit != 0)  //decrements the sum by 10 each time to determine how many digits there are
    {  
        digit = digit / 10;  
        count++;  //the decrement by 10 will only loop for as many digits as there ar ein the number, therefore the count of th enumber of times the sum can be divided by 10 is equivalent to the number of digits
    }  

    printf("thread (TID %d) identifies X + Y = %d as a %d digit number\n", *(int *) thread_id, S, count);
}

int main (int argc, char *argv[])
{
    /*creates pipe and stores its numerical value in status*/
    pipe(port);

    /*if the pipe creation is unsuccessful, raises an error*/
    if(pipe(port) < 0)
    {
        perror("pipe() unsuccessful\n");
        exit(0);
    }

    /*parent process*/
    p = getpid();
    X = atoi(argv[1]); //converts the first command line argument into an integer and stores it in X
    Y = atoi(argv[2]); //converts the second command line argument into an integer and stores it in Y

    printf("parent (PID %d) receives X = %d and Y = %d from the user\n", p, X, Y);
    printf("parent (PID %d) writes X = %d and Y = %d to the pipe\n", p, X, Y);
    write(port[1], &X, sizeof(X)); //writes the value of X into the pipe
    write(port[1], &Y, sizeof(Y)); //write the value of Y into the pipe

    int tid1 = 100; //assigns the thread id as 100
    pthread_create(&t1, NULL, sum, &tid1); //creates the first thread and puts the thread id as its argument
    pthread_join(t1, NULL); //waits for first thread to complete before going to the next one

    int tid2 = 101; //assigns the thread id as 101
    pthread_create(&t2, NULL, odd_even, &tid2); //creates the second thread and puts the thread id as its argument
    pthread_join(t2, NULL); //waits for second thread to complete before going to the next one

    int tid3 = 102; //assigns the thread id as 102
    pthread_create(&t3, NULL, digit_count, &tid3); //creates the third thread and puts the thread id as its argument
    pthread_join(t3, NULL); //waits for third thread to complete

    printf("main program is terminating...\n");

    return(0);
}
