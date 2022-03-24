/*CS2211a 2020*/
/*Assignment 04*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 16 2020*/

#include "headers.h"

*sent strInput(char *str){

    sent.numWords = 0;
    wrd.charCount = 0;

    for(int count = 0; count < str.length(); count++){

        wrd.wordPos = count;
        wrd.cP = *(str + count); //Sets the character pointer to the position count in the character array//
        if(isBlank(wrd.cP)) //if the for loop finds an empty space then the count of words increments and the word position is marked in the sentence
        {
            sent.numWords += 1;
            wrd.wordPos = count +1
        } else if(wrd.cP == '\0'){ //The '\0' denotes the end of the input string so the word counter will increment and the for loop will exit
            sent.numWords += 1;
            break;
        } else{
            wrd.charCount += 1;
        }

    }

    pointer = (sent *)realloc(str, sent.numWords*(sizeof(sent))); //reallocate the data inside the sentence pointer into dynamic memory

    /*psuedocode - I did not get to finish this assignment due to multiple biology and other cs courses midterms, assignments, and labs. Will do better on the next one
    
    return the sentence structure created, pointer*/
}