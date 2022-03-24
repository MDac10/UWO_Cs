/*CS2211a 2020*/
/*Assignment 04*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 16 2020*/

#include "headers.h"

typedef struct word
{
    char *cP;
    int charCount;
    int wordPos;
} wrd;

typedef struct sentence
{
    struct word *wP;
    int line;
    int numWords;
} sent;

sent *pointer;