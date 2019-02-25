#include <stdio.h>
#include <stdlib.h>

int getStringLength(char* string, int wantRawSize){//include or exclude hidden characters
    int index = 0;
    int length = 0;
    while(string[index]){
        if(wantRawSize || (string[index] != ' ' && string[index] != '\n'))
            length++;

        index++;
    }
    return length;
}

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    puts("Type in your name:");

    char name[50];
    fgets(name, sizeof(name), stdin);
    printf("Your name is %d characters long", getStringLength(name, 0));
    return 0;
}