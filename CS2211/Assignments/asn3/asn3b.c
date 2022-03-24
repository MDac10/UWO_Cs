/*CS2211a 2020*/
/*Assignment 3*/
/*Megan Da Costa*/
/*mdacos2*/
/*October 17 2020*/

#include <stdio.h>

/*This function asks for integer input from the user on loop*/
/*If 0 is input by the user then the program will terminate*/
/*Any other integer value is then counted towards from 1 and with each iteration the program checks to see that iterations value
of remainder compared to an integer that starts at two and counts up to the value of iterations. If there are no remainders (the 
iteration that the program is on while counting up to the input value is even) then the counter will increment and if the counter 
is 1 then the program value will be summed with that iteration number/value*/ 
/*Once the value input goes thorugh it's total number of iterations then the program will print the total in the program value */

int main(){
    int value, even, input, counter;
    while(1){ /*While the input is not 0...*/
        value = 0; /*Initializes the output value to 0*/
        printf("Input? ");
        scanf("%d", &input);
        if(input == 0) break; /*If the user inputs 0 then the while loop (what will keep asking for input) will exit and the program will go to the return line and terminate */
        for(int i = 1; i < input; i++){
            counter = 0;
            for(even = 2; even <= i; even++) /*starts the even marker at 2 and counts until even <= iteration i value*/
            if(i % even == 0) counter++; /*If i value is evenly divisible by the current even value then the counter is incremented*/
            if(counter == 1) value = value + i; /*When counter reaches a value of 1 (it starts at 0) then the output value has the iteration i value added to it*/
        }
        printf("The final total is: %d\n", value);
    }
    return 0;
}
