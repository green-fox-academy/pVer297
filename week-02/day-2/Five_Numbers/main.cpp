#include <iostream>

int main() {
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int userInput[5];

    std::cout << "Please provide me five number:(int)" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> userInput[i];
    }

    int *inputPointer = userInput;

    std::cout << "The array contains these numbers:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << *(inputPointer + i) << " ";
    }

    return 0;
}