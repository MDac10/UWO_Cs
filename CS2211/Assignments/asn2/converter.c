/*CS2211a 2020*/
/*Assignment 2 - part 1*/
/*Megan Da Costa*/
/*mdacos2*/
/*October 2 2020*/
#include <stdio.h>

char option, direction; /*gloabl variables: option for what the user chooses for their conversion, direction for which way the conversion will go, convert as the value to be converted and answer as the conversion value*/
float convert, answer;

void kmToM() /*void function so it will run and then once it reaches it's last line it will go back to the main function*/
{   /*user gets prompted to input K or M and if it's valid, taht value will be assigned to the direction variable*/
    printf("What direction is the conversion (K - kilometers to miles, M - miles to kilometers):\n");
    scanf(" %c", &direction);
    while((direction != 'K') && (direction != 'M'))  /*If anything other than K or M is entered at this step it will keep asking for a valid input*/
    {
        printf("Invalid input. Try again.\n");
        printf("What direction is the conversion (K - kilometers to miles, M - miles to kilometers): \n");
        scanf(" %c", &direction);
    }
    printf("Input value to convert: \n"); /*user will input the value that they want to convert here and that value will be assigned to the variable convert (to be converted)*/
    scanf("%f", &convert);
    if(direction == 'K')
    {
        answer = convert/ 1.609; /*conversion from kilometers to miles*/
        printf("%.2f km converts to %.2f miles. \n", convert, answer);
    } 
    else
    {
        answer = convert * 1.609; /*conversion from miles to kilometers*/
        printf("%.2f miles converts to %.2f km. \n", convert, answer);
    }
}

void lToG() /*void function so it will run and then once it reaches it's last line it will go back to the main function*/
{ /*user gets prompted to input L or G and if it's valid, taht value will be assigned to the direction variable*/
    printf("What direction is the conversion (L - litres to gallons, G - gallons to litres): \n");
    scanf(" %c", &direction);
    while((direction != 'L') && (direction != 'G')) /*If anything other than G or M is entered at this step it will keep asking for a valid input*/
    {
        printf("Invalid input. Try again.\n");
        printf("What direction is the conversion (L - litres to gallons, G - gallons to litres): \n");
        scanf(" %c", &direction);
    }
    printf("Input value to convert: \n"); /*user will input the value that they want to convert here and that value will be assigned to the variable convert (to be converted)*/
    scanf("%f", &convert);
       if(direction == 'L')
       {
        answer = convert * 0.264172;  /*conversion from litres to gallons*/
        printf("%.2f L converts to %.2f gallons. \n", convert, answer);
    } 
    else
    {
        answer = convert * 3.785411784;  /*conversion from gallons to litres*/
        printf("%.2f gallons converts to %.2f L. \n", convert, answer);
    }

}

void cmToInch() /*void function so it will run and then once it reaches it's last line it will go back to the main function*/
{ /*user gets prompted to input C or I and if it's valid, taht value will be assigned to the direction variable*/
    printf("What direction is the conversion (C - centimeters to inches, I - inches to centimeters):\n");
    scanf(" %c", &direction);
    while((direction != 'C') && (direction != 'I')) /*If anything other than L or G is entered at this step it will keep asking for a valid input*/
    {
        printf("Invalid input. Try again.\n");
        printf("What direction is the conversion (C - centimeters to inches, I - inches to centimeters): \n");
        scanf(" %c", &direction);
    }
    printf("Input value to convert: \n"); /*user will input the value that they want to convert here and that value will be assigned to the variable convert (to be converted)*/
    scanf("%f", &convert);
    if(direction == 'C')
    {
        answer = convert/2.54;  /*conversion from centimeters to inches*/
        printf("%.2f cm converts to %.2f inches. \n", convert, answer);
    }
    else
    {
        answer = convert * 2.54;  /*conversion from inches to centimeters*/
        printf("%.2f inches converts to %.2f cm. \n", convert, answer);
    }

}

void celToFahr() /*void function so it will run and then once it reaches it's last line it will go back to the main function*/
{ /*user gets prompted to input C or F and if it's valid, taht value will be assigned to the direction variable*/
    printf("What direction is the conversion (C - celsius to fahrenheit, F - fahrenheit to celsius):\n");
    scanf(" %c", &direction);
    while((direction != 'C') && (direction != 'F')) /*If anything other than C or F is entered at this step it will keep asking for a valid input*/
    {
        printf("Invalid input. Try again.\n");
        printf("What direction is the conversion (C - celsius to fahrenheit, F - fahrenheit to celsius): \n");
        scanf(" %c", &direction);
    }
    printf("Input value to convert: \n"); /*user will input the value that they want to convert here and that value will be assigned to the variable convert (to be converted)*/
    scanf("%f", &convert);
    if(direction == 'C')
    {
        answer = (float)((convert*(1.8))+32);  /*conversion from celsius to fahrenheit*/
        printf("%.2f C converts to %.2f F. \n", convert, answer);
    } 
    else
    {
        answer = (float)((convert-32)/(1.8));  /*conversion from fehrenheit to celsius*/
        printf("%.2f F converts to %.2f C. \n", convert, answer);
    }

}

int main(void){
    printf("Enter what conversion you want to do (1 - km/miles, 2 - L/gal, 3 - cm/inches, 4 - C/F, 5 - quit): \n");
    scanf(" %c", &option); /*user inputs a number from 1-5 (ID as characters)*/
    while((option != '1') && (option != '2') && (option != '3') && (option != '4') && (option != '5'))
    { /*If option input is not 1-5 then user is prompted again until they choose a valid input*/
        printf("Not a valid input. Try again.\n");
        printf("Enter what conversion you want to do (1 - km/miles, 2 - L/gal, 3 - cm/inches, 4 - C/F, 5 - quit): \n");
        scanf(" %c", &option);
    }
    while(option != '5') /*Program will keep asking for conversion type input until 5 aka the 'quit' value is entered*/
    {
        if(option == '1')
        {
            kmToM(); /*goes to helper method that converts km to miles and vice versa*/
        } 
        else if(option == '2')
        {
            lToG(); /*goes to helper method that converts litres to gallons and vice versa*/
        } 
        else if(option == '3')
        {
            cmToInch(); /*goes to helper method that converts centimeters to inches and vice versa*/
        }
        else if(option == '4')
        {
            celToFahr(); /*goes to helper method that converts celsius to fahrenheit and vice versa*/
        }
        printf("Enter what conversion you want to do (1 - km/miles, 2 - L/gal, 3 - cm/inches, 4 - C/F, 5 - quit): \n");
        scanf(" %c", &option);
    } 
    printf("End of program.\n");
    return 0;
}
