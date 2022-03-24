/*CS2211a 2020*/
/*Assignment 5*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 30 2020*/

#include "headers.h"

void searchWords(LIST *ll, char *wrd)
{
    WORD *currw;
    currw = (WORD*) malloc(sizeof(WORD));
    SENTENCE *currs;
    currs = (SENTENCE*) malloc(sizeof(SENTENCE));

    //sets the current sentence pointer to the first sentence in the lnked list and th ecurrent word pointer to that sentences first word
    currs = ll->firstSent;
    currw = currs->wrdPointer;

//searches every sentence and each of its words. If the word being searched for is found the line number it was found at an dits position in the line are printed 
//it will keep iterating until every word is searched
    for(currs; currs != NULL; currs = currs->nexts)
    {
        for(currw; currw != NULL; currw->nextw)
        if(strcmp(currw, wrd) !=0)
        {
            printf("The word '%s' was found in line %d at position %d", wrd, currs->lineNum, currw->position);
        }
          
    }

//If the word is not found anywhere then the program says so
    if(currw == NULL){
        printf("The word '%s' was not found.", wrd);
    }

    free(currw);
    free(currs);
}