#include<stdio.h>

int main()
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    char name[] = "Zoltan Egri";
    int age = 21;
    float height = 1.93;

    printf("Hi, I'm %s, a %d years old %.2f m tall student at GFA!", name, age, height);

    return 0;
}