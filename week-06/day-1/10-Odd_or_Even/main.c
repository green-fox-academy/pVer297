#include <stdio.h>
#include <stdlib.h>

int isEven(int number){
    return (number % 2) == 0;
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    int userInput;

    puts("Please type in a number:");

    scanf("%d", &userInput);

    if(isEven(userInput)){
        puts("Your number is even!");
    } else {
        puts("Your number is odd!");
    }

    return 0;
}