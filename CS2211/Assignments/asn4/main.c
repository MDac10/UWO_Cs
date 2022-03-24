/*CS2211a 2020*/
/*Assignment 04*/
/*Megan Da Costa*/
/*251009855*/
/*November 16 2020*/

#include "headers.h"

int main(){
    char str[1000];               //initial character array that will be dynamically allocated
    printf("Enter a string: \n");
    fgets(str, 1000, stdin);      //Input string gets stored i the character array str
    char *ptr = &(str);           //The character pointer will be set to the address of the character array
    sent *sentence;
    wrd *words;
    sent.line = 0;

    while(strcmp(str, "\n") != 0){   //While the user doesn't enter a blank line...
        sent.line += 1;
        sentence = inputFunctions.strInput(ptr); //Puts the sentence through the inputFunctions 
        printf("Enter a string: \n") //Prompts teh user again
        fgets(str, 1000, stdin);
    }

    outputFunctions.strWordOutput(sentence); //Once a blank line is entered the words and lines that were entered will be printed by tehse functions
    outputFunctions.strLineOutput(sentence);

    printf("Enter a word to search: \n");  
    fgets(str, 1000, stdin);
    while(strcmp(str, "\n") != 0)  //While the user doesn't enter a blank space
    {
        outputFunctions.searchWord(ptr);  //Sends the pointer to the address of the word entered to the serachWord function
        printf("Enter a word to search: \n"); //Continues to prompt the user for more words to serach for
        fgets(str, 1000, stdin);
    }

    return 0;
}