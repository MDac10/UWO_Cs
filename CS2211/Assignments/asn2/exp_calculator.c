/*CS2211 2020*/
/*Assignment 2 - part 2*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*October 3 2020*/

#include <stdio.h>
#include <stdlib.h>

float base, result;  /*global variables: base for the non-zero base input, exponent for the integer exponent, and result for that calculation*/
int exponent;

float expCalculator(float a, int n) /*expCalculator function takes in the base (a) and exponent (n) and returns a float version of the answer*/
{
    if(n == 0) return 1; /*Base case where the exponent is equal to one*/
    if(n > 0)
    {
        if(n % 2 == 0)
        {
            result = (float)(expCalculator(a, (n/2))); /*recursive call*/
            return  (result * result);  /*a^(n/2)*a^(n/2) for all even exponent values*/
        }
        else
        {
            result = (float)(expCalculator(a, (n-1)/2)); /*recursive call*/
            return (a * result * result);   /*a*a^((n-1)/2)*a^((n-1)/2)*/
        } 
    } 
    else
    {
        result = (float)(expCalculator(a, abs(n))); /*recursive call*/
        return (1/result);  /*1/(a^n)*/
    }
    
}

int main(void){
    printf("Enter base value or 0 to exit:\n");  /*input either 0 to end the program or any numeric value to be the base for the calculation*/
    scanf("%f", &base);
    while(base != 0) /*program will keep asking for input of base and exponent after calculation is done if base is not 0 (exit)*/
    {
        printf("Enter integer exponent value:\n");
        scanf("%d", &exponent);
        printf("Base %.2f to the exponent %d equals %.3f. \n", base, exponent, (float)expCalculator(base, exponent)); /*call to recursive helper function expCalculator*/
        printf("Enter base value or 0 to exit:\n");
        scanf("%f", &base);
    }
    printf("End of calculator program.\n");
    return 0;
}
