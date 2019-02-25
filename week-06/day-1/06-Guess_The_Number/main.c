#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stored number is lower
    // You found the number: 8

    srand(time(NULL));
    int storedNumber = rand() % 99 + 1;
    printf("You got a number between 1 and 100, go guess it!\n");
    char userInput[5];
    while(1){
        fgets(userInput, sizeof(userInput), stdin);
        int number = atoi(userInput);
        if(number == storedNumber){
            printf("You guessed it! The number was %d\n", storedNumber);
            break;
        } else if(number > storedNumber){
            printf("The stored number is lower, try again!\n");
        } else if(number < storedNumber){
            printf("The stored number is higher, try again!\n");
        }
    }
    return 0;
}