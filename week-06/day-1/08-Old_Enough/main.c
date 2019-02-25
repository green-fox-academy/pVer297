#include <stdio.h>
#include <stdlib.h>

int legalAge(int age){
    return age >= 18;
}


int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    puts("Please type in your age:");
    int age;
    scanf("%d", &age);
    if(legalAge(age)){
        puts("You are old enough to buy alcohol");
    } else {
        puts("You can't buy alcohol yet, you are too young");
    }
    return 0;
}