#include <stdio.h>
#include <stdlib.h>

int isEqual(int number1, int number2){
    return number1 == number2;
}

int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int num1;
    int num2;

    puts("Please type in two numbers separated by space!(eg. 5 6)");
    scanf("%d %d", &num1, &num2);

    if(isEqual(num1,num2)){
        puts("Hooray, your numbers are equal");
    } else {
        puts("Sadly, your numbers are not equal");
    }

    return 0;
}