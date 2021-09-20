#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int child_1, child_2, child_2_1; //create int holders for child PIDs
    
    child_1 = fork(); //child 1 is created
    wait(NULL); //parent will wait for child_1 to complete before continuing

    if(child_1 > 0) //original parent
    {
        child_2 = fork(); //child 2 s created
        wait(NULL); //parent will wait for child 2 to complete

        if(child_2 == 0) //looking at child_2
        {
            child_2_1 = fork(); //child 2.1 is created
            
            if(child_2_1 == 0) //looking at child_2_1
            {
                execl("external_program.out", strcat(child_2_1, " for child_2.1"), NULL);

            }

        }
    }

    if(child_1 == 0)
    {
        execl("external_program.out", strcat(child_1, " for child_1"), NULL);
    }

    return 0;
}
