#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchString(char* string, char* subString)
{
    int index = 0;
    int subIndex = 0;
    while (string[index]) {
        if (string[index] == subString[subIndex]) {
            subIndex++;
        } else if (subIndex > 0) {
            index--;
            subIndex = 0;
        }
        if (subIndex == strlen(subString))
            return 1;
        index++;
    }
    return 0;
}

int isSubstring(char* string1, char* string2)
{
    if (strlen(string1) == strlen(string2))
        return -1;

    if (strlen(string1) < strlen(string2)) {
        return searchString(string2, string1);
    } else {
        return searchString(string1, string2);
    }
}

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    puts("Type in two strings");

    char input1[50];
    char input2[50];

    fgets(input1, sizeof(input1), stdin);
    fgets(input2, sizeof(input2), stdin);

    strtok(input1, "\n");
    strtok(input2, "\n");

    int returnState = isSubstring(input1, input2);
    switch (returnState) {
        case 0: puts("The shorter is not substring of the longer");
            break;
        case 1: puts("The shorter is substring of the longer");
            break;
        case -1: puts("They are the same length!");
            break;
    }
    return 0;
}