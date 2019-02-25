#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int sumOfDigits(int number)
{
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int equalDigits(int num1, int num2)
{
    return sumOfDigits(num1) == sumOfDigits(num2);
}

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    int number1;
    int number2;

    puts("Type in two numbers separated by space!(eg. 123 456)");
    scanf("%d %d", &number1, &number2);

    if (equalDigits(number1, number2)) {
        printf("Your numbers digits are equal!\n"
               "Their value is: %d\n", sumOfDigits(number1));
    } else {
        puts("Your numbers digits are not equal!");
    }

    return 0;
}