#include <iostream>

// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
// (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
// have 3 ears, because they each have a raised foot. Recursively return the
// number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).

int countEars(int numOfBunnies)
{
    if (numOfBunnies < 1) return 0;

    if((numOfBunnies % 2) == 0) return 2 + countEars(numOfBunnies - 1);
    else return 3 + countEars(numOfBunnies - 1);
}

int countBunnies(int numOfBunnies)
{
    if (numOfBunnies < 1) return 0;
    return countEars(numOfBunnies);
}

int main()
{
    std::cout << "How many rabbit ears do you want to count?" << std::endl;
    std::cout << "Every odd rabbit has an extra leg up too!" << std::endl;

    int userInput;
    std::cin >> userInput;
    std::cout << userInput << " rabbits have " << countBunnies(userInput) << " white fluffs up in the air" << std::endl;
    return 0;
}