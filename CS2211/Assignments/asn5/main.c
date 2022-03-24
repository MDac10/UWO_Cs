/*CS2211a 2020*/
/*Assignment 5*/
/*Megan Da Costa*/
/*251009855*/
/*mdacos2*/
/*November 30 2020*/

#include "headers.h"

int main(void)
{
    char str[1000];
    char *strptr;

//makes a new empty list
    LIST *list = controlStructure();
    SENTENCE *sent;

//method for user to input various sentences
    printf("Please enter a sentence: \n");
    fgets(str, sizeof(str), stdin);
    strptr = &str;

//while the user doesn't enter an empty line, the program will keep processing and asking for more lines
    while(!(strcmp(str, "") == 0)){
        list = inputSent(list, strptr);

        printf("Please enter a setence: \n");
        fgets(str, sizeof(str), stdin);
    }

//prints out the sentences input
    outputWords(list);

//method for finding an input word in the prevously entered sentences
    printf("Please enter a word to search for: \n");
    fgets(str, sizeof(str), stdin);

//while the user doesn't enter an empty line, the program will keep asking for another word to search for
    while(!(strcmp(str, "") == 0))
    {
        //search for the input word in all sentences and prints out if it was found or not and where it was found (line number and position)
        searchWords(list, strptr);

        printf("Please enter a word to search for: \n");
        fgets(str, sizeof(str), stdin);
    }

//method for removing a line from the sentences input
    int line;
    printf("Please enter a line number to delete: \n");
    fgets(line, sizeof(line), stdin);

//while the user doesn't enter an empty line, the program will keep asking for lines to remove
    while(line != "")
    {
        if(line > list->numSents)
        { 
            printf("Input out of bounds. Try again.\n");
            printf("Please enter a line number to delete: \n");
            fgets(line, sizeof(line), stdin);
        }

        //function to remove a line
        line = removeLine(list, line);
        if(sent == NULL)
        {
            printf("This line was not found.");
        }
        outputWords(line);

        printf("Please enter a line number to delete: \n");
        fgets(line, sizeof(line), stdin);
    }

//frees the memory allocated to these structures
    free(sent);
    free(list);
}