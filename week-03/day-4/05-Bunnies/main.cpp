#include <iostream>

// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).

int countEars(int numOfBunnies)
{
    if (numOfBunnies < 1) return 0;
    return 2 + countEars(numOfBunnies - 1);
}

int countBunnies(int numOfBunnies)
{
    if (numOfBunnies < 1) return 0;
    return countEars(numOfBunnies);
}

int main()
{
    std::cout << "How many rabbit ears do you want to count?" << std::endl;

    int userInput;
    std::cin >> userInput;
    std::cout << userInput << " rabbits have " << countBunnies(userInput) << " ears" << std::endl;
    return 0;
}