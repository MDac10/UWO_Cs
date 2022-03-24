/*CS2211a 2020*/
/*Assignment 5*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 30 2020*/

#include "headers.h"

struct SENTENCE* createNode(char *itemptr)
{
    WORD *wrdptr;
    int numwrd = 0;
    int pos = 0;

    wrdptr->string = itemptr;

//looks through the input string, making a new word every time a space is encountered or until the '\0' is found, incrementing the word count as it encounters each new word
    for(int charIndex = 0; charIndex <= strlen(itemptr); charIndex++)
    {
        if(*(itemptr + charIndex) == " " || *(charIndex + itemptr) == "\0")
        {

            wrdptr = (WORD*) malloc(sizeof(WORD));
            wrdptr->numChars = charIndex + 1;
            wrdptr->position = pos++;
            charIndex = charIndex++;
        }

        wrdptr->nextw = *(itemptr + charIndex);
        numwrd++;
    }

//makes the new sentence structure and assigns it the proper values
    SENTENCE *nodeptr;
    nodeptr = (SENTENCE*) malloc(sizeof(SENTENCE));
    nodeptr->lineNum += 1;
    nodeptr->wrdPointer = wrdptr->string; 
    nodeptr->numWords = numwrd;
    
    return nodeptr;
}