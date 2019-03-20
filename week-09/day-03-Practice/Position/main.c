#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void findLetters(char* string, char letter)
{
    int index = 0;
    while (string[index]) {
        if (string[index] == letter)
            printf("%c @ %d\n", string[index], index + 1);

        index++;
    }
}

int main()
{
    char string[55] = "This is a string for testing";
    findLetters(string, 'i');

    return 0;
}