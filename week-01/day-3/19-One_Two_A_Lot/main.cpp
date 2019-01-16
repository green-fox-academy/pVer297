#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot
    std::cout << "Please provide me a number:(integer)" << std::endl;
    int userInput;
    std::cin >> userInput;
    if (userInput <= 0){
        std::cout << "Not Enough" << std::endl;
    } else if (userInput == 1) {
        std::cout << "One" << std::endl;
    } else if (userInput == 2) {
        std::cout << "Two" << std::endl;
    } else {
        std::cout << "A Lot" << std::endl;
    }


    return 0;
}