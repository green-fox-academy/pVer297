#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int numberOfChickens;
    int numberOfPigs;

    std::cout << "How many chickens does the farmer have?" << std::endl;
    std::cin >> numberOfChickens;
    std::cout << "How many pigs does the farmer have?" << std::endl;
    std::cin >> numberOfPigs;

    int numberOfLegs = (numberOfPigs*4)+(numberOfChickens*2);

    std::cout << "The animals have " << numberOfLegs << " legs in total" << std::endl;
    return 0;
}