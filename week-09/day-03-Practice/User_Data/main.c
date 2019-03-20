#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main()
{
    puts("Please type in your full name and your age");
    char userInput[50];
    gets(userInput);
    int foundWords = 0;
    char first_name[25];
    char last_name[25];
    int age = 0;

    for (char* word = strtok(userInput, " "); word != NULL; word = strtok(NULL, " ")) {
        switch (foundWords) {
            case 0:strcpy(first_name, word);
                break;
            case 1:strcpy(last_name, word);
                break;
            case 2:age = atoi(word);
                break;
            default: break;
        }

        foundWords++;
    }

    printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

    return 0;
}