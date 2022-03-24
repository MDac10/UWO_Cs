/*CS2211a 2020*/
/*Assignment 5*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 30 2020*/

#include "headers.h"

void outputWords(LIST* list)
{
    SENTENCE *curr;
    WORD *wrd;

//from the first sentence to te last, this method will print out every sentence (word for word), each in a new line
    for(curr = list->firstSent; curr = NULL; curr = curr->nexts)
    {
        for(wrd = curr->wrdPointer; wrd = NULL; wrd = wrd->nextw)
        {
            prinf("%s", wrd);
        }
        printf("\n");
    }
}