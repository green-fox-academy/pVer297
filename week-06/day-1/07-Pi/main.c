#include <stdio.h>
#include <stdlib.h>
#include "circleFunctions.h"



// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI



int main()
{
    puts("Type in the radius of your circle:");
    char userInput[10];
    fgets(userInput,sizeof(userInput),stdin);
    printf("The area of your circle is %.3f\n"
           "The circumference of your circle is %.3f\n",
           calcArea(atoi(userInput)),
           calcCircumference(atoi(userInput)));
    return 0;
}