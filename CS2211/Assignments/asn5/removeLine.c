/*CS2211a 2020*/
/*Assignment 5*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 30 2020*/

#include "headers.h"

struct LIST* removeLine(LIST* list, int linePos)
{
    SENTENCE *curr, *prev;

//searches the list until it reaches the correct line number to delete
    for(curr = list->firstSent, prev = NULL; curr != NULL && (SENTENCE*) curr->lineNum != linePos; prev = curr, curr = curr->nexts);

    if(curr == NULL) //if the line is not in the list it reurns NULL
    {
        return list;
    }
    else if(prev == NULL) //if the line to delete is the first line in the list, set the new head pointer to the line after the one to be deleted
    {
        list->firstSent = curr->nexts;
    }
    else
    {
        prev->nexts = curr->nexts;
    }

    free(curr->wrdPointer);
    free(curr);

//returns the new modified list (after removal)
    return list;
}