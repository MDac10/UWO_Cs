/*CS2211a 2020*/
/*Assignment 5*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 30 2020*/

#include "headers.h"

struct LIST* controlStructure(void)
{
    //creates the control structure for the linked list. This list is empty (points to null with var numSents set to 0)
    LIST* linked;
    linked = (LIST*) malloc (sizeof(LIST));
    if(linked)
    {
        linked->firstSent = NULL;
        linked->numSents = 0;
    }
    return linked;
}

