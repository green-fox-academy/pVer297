#include <stdio.h>
#include <string.h>
#include "lorem.h"
// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main()
{
    FILE* fptr;
    while (1) {
        fptr = fopen("my-file.txt", "r");

        if (fptr == NULL) {
            createLorem("my-file.txt", fptr);
        } else {
            break;
        }
    }
    char currentLine[256];
    while (fgets(currentLine, sizeof(currentLine), fptr)) {
        printf("%s", currentLine);
    }
    fclose(fptr);
    return 0;
}