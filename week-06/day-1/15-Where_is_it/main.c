#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findChar(char* string, char charToCheck)
{
    int appearance = -1;
    int index = 0;
    while (string[index]) {
        if (string[index] == charToCheck) {
            appearance = index;
            break;
        }
        index++;
    }
    return appearance;
}

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    puts("Type in a line then a character to check");
    char userInput[50];
    char charToCheck;
    fgets(userInput, sizeof(userInput), stdin);
    charToCheck = (char) fgetc(stdin);

    if (findChar(userInput, charToCheck) >= 0) {
        printf("The first appearance of \'%c\' is at %d", charToCheck, findChar(userInput, charToCheck));
    } else {
        puts("There is no such character in the string");
    }

    return 0;
}