#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* appendA(char* string)
{
    char toAppend = 'a';
    int index = 0;

    while(string[index]){
        if(string[index] == '\n' || string[index] == '\0'){
            string[index] = toAppend;
            string[index+1] = '\0';
            break;
        }
        index++;
    }
    return string;
}

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char userInput[50];

    puts("Please type in something:");
    fgets(userInput, sizeof(userInput) - 1, stdin);
    puts(appendA(userInput));

    return 0;
}