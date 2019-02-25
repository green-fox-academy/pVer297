#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the reminder of 22 divided by 13

    // Store the results in variables and use them when you display the result

    int adding = 13 + 22;
    int subtracting = 22 - 13;
    int multiplicating = 22 * 13;
    double division = 22.0 / 13.0;
    int reminder = 22 % 13;

    printf("22 + 13 = %d\n22 - 13 = %d\n22 * 13 = %d\n22 / 13 = %.3f\n22 %c 13 = %d",
           adding, subtracting, multiplicating, division, '%', reminder);

    return 0;
}