#include <iostream>

int main() {
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    int userInput[5];

    std::cout << "Please provide me five number:(int)" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> userInput[i];
    }
    std::cout << "The memory addresses for the inputs are:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << userInput + i << " ";
    }

    return 0;
}