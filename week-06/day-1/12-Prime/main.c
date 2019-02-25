#include <stdio.h>
#include <stdlib.h>

int isPrime(int number)
{
    if (number <= 3) {
        return number > 1;
    } else if (number % 2 == 0 || number % 3 == 0) {
        return 0;
    }
    int i = 5;
    while (i * i <= number) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0;
        }
        i += 6;
    }
    return 1;
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    puts("Type in a number:");

    int userInput;

    scanf("%d", &userInput);

    if(isPrime(userInput)){
        puts("Your number is prime");
    } else {
        puts("Your number is not a prime");
    }

    return 0;
}