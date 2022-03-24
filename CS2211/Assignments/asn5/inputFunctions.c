/*CS2211a 2020*/
/*Assignment 5*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 30 2020*/

#include "headers.h"

LIST* inputSent(LIST* list, char *string)
{
//function to create a new node given a string input
    SENTENCE *newL = createNode(string);

//Adds all new lines to the front of the list
    newL->nexts = list->firstSent;

    list->firstSent = newL;
    list->numSents++;   
}