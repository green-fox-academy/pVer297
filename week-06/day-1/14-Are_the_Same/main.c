#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toLower(char* string)
{
    int index = 0;
    while (string[index]) {
        if (string[index] < 91 && string[index] > 64)//char is uppercase
            string[index] += 32; //setting the char equal to its lowercase value
        index++;
    }
    return string;
}

int equalStrings(char* string1, char* string2)
{

    toLower(string1);
    toLower(string2);

    int index = 0;
    while (string1[index] && string2[index]) {
        if (string1[index] != string2[index])
            return 0;
        index++;
    }
    return 1;
}

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    puts("Please type in two words:");

    char input1[50];
    char input2[50];

    scanf("%s %s", input1, input2);
    if (equalStrings(input1, input2)) {
        puts("Your strings are the same");
    } else {
        puts("Your strings are not the same");
    }
    return 0;
}