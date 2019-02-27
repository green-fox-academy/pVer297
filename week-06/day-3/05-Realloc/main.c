#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* numbers = NULL;
    int* counter = NULL;

    puts("Please give me a number:");

    int userInput;
    scanf("%d", &userInput);

    numbers = (int*) calloc(userInput, sizeof(int));

    printf("Please type in %d numbers:\n", userInput);

    int sum = 0;
    for (int i = 0; i < userInput; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    counter = (int*) calloc(sum, sizeof(int));

    for (int i = 0; i < sum; i++) {
        counter[i] = i;
        printf("%d\n", counter[i]);
    }

    free(numbers);
    free(counter);
    return 0;
}