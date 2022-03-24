/*CS2211a 2020*/
/*Assignment 3*/
/*Megan Da Costa*/
/*mdacos2*/
/*October 17 2020*/

#include <stdio.h>
#include <string.h>

void main(){

    /*This array can be changed any way the user wishes and you will still get the right outputs*/
    /*int array[] = { 12,63,44,89,3,55,73,27,37,18 };*/
    int array[] = {12, 63, 44, 89, 3, 55, 73, 27, 37, 18, 6, 24, 31, 46, 58};

    int size = sizeof(array); /* These two integer values will continuously be reused*/
    int length = sizeof(array)/sizeof(array[0]); /*length would be calculated by dividing the actual byte size of the array by the byte size of a single element in the array*/

    printf("\nSize of array: %d bytes\n", size);
    printf("Length of array: %d elements\n", length);

    printf("\nPart 1:\n");
    printf("The values stored in the array are: \n");
    for(int i = 0; i < length; i++){ /*for loop that prints every value in the array with five spaces between each value*/
        printf("%d     ", array[i]);
    }
    printf("\n");

    printf("\nPart 2:\n");
    printf("The values store in the array in reverse order are: \n");
    for(int j = length-1; j >= 0; j--){ /*Start from one of the array using value "length-1" and ending at value 0 to end at the beginning of the array*/
        printf("%d     ", array[j]);
    }
    printf("\n");

    printf("\nPart 3:\n");
    int position, smallest = array[0]; /*assigns the original smallest value as the first element in the array*/
    char posTerm[3]; /*the suffix string saves enough space of the null terminator*/
    for(int k = 1; k < length; k++){
        if(array[k] < smallest){  /*If any values in the other slots of the array are smaller than the item currently in 'smallest' that value replaces it*/
            smallest = array[k];
            position = k; /*Keeps track of the current position in teh array to determine the suffix for writting out the place in the array*/
        }
    }
    if(position == 0){  /*The various suffixes for positions in the arra*/
        strcpy(posTerm, "st");
    }
    else if (position == 1)
    {
        strcpy(posTerm, "nd");
    }
    else if (position == 2)
    {
        strcpy(posTerm, "rd");
    }
    else
    {
        strcpy(posTerm, "th");
    }
    printf("The smallest value stored in the array is: \n");
    printf("Value: %d at the %d%s position from the left\n", smallest, position+1, posTerm);
    printf("\n");

    printf("\nPart 4:\n");
    printf("The sum (total) value of the array is: \n");
    int sum = 0;
    for(int l = 0; l < length -1; l++){
        sum = sum + array[l]; /*adds all the values in the array together for the duration of the for loop*/
        printf("%d + ", array[l]);
    }
    printf("%d equals: %d\n", array[length-1], sum + array[length-1]); /*The last value in the array are added in here*/

    printf("\nPart 5:\n");
    printf("Copy the array into a new array, but in reverse order:\n");
    int newArray[length]; /*makes a new array the same size as the original array*/
    int newReverse = 0;
    for(int m = length-1; m >= 0 ; m--){
        newArray[newReverse] = array[m];
        newReverse++;
    }
    printf("Original array: \n");
    for(int i = 0; i < length; i++){
        printf("%d     ", array[i]);
    }
    printf("\nNew (reversed) array: \n");
    for(int j = 0; j < length; j++){
        printf("%d     ", newArray[j]);
    }
    printf("\n");

    printf("\nPart 6:\n");
    printf("Switch the first value in the array with the last value in the array:\n");
    printf("Original array:\n");
    for(int i = 0; i < length; i++){
        printf("%d     ", array[i]);
    }
    int temp = array[0]; /*temporaty variable stores the int in the first position of the array*/
    array[0] = array[length-1]; /*This swaps the values in first and last positions in the array*/
    array[length-1] = temp;
    printf("\nChanged array:\n");
    for(int i = 0; i < length; i++){
        printf("%d     ", array[i]);
    }
    printf("\n");

    printf("\nPart 7:\n");
    printf("Sort the array in ascending order:\n");
    printf("Original array:\n");
    for(int i = 0; i < length; i++){
        printf("%d     ", array[i]);
    }
    for(int j = 0; j < length; j++){
        for(int k = 0; k < length; k++){
            if(array[k] > array[j]){ /*looks to see if the value a position ahead is larger than the value in an earlier position and if so, swaps them*/
                int temp2 = array[j];
                array[j] = array[k];
                array[k] = temp2;
            }
        }
    }
    printf("\nChanged array:\n");
    for(int l = 0; l < length; l++){
        printf("%d     ", array[l]);
    }
    printf("\n");
}
