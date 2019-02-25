#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

double calcArea(double radius){
    return radius * radius * PI;
}

int main()
{
    puts("Type in the radius of your circle:");
    char userInput[10];
    fgets(userInput,sizeof(userInput),stdin);
    printf("The area of your circle is %.3f", calcArea(atoi(userInput)));
    return 0;
}