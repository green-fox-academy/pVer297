#include <iostream>

int main() {
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it
    std::cout << "How many numbers do you want to compare?" << std::endl;
    int numberOfInputs;
    std::cin >> numberOfInputs;

    std::cout << "Please type in your numbers:" << std::endl;
    int inputArray[numberOfInputs];
    for (int i = 0; i < numberOfInputs; i++) {
        std::cin >> inputArray[i];
    }

    int *maxPointer = inputArray;
    for (int i = 0; i < numberOfInputs; i++) {
        if (inputArray[i] > *maxPointer) {
            maxPointer = inputArray + i;
        }
    }
    std::cout << "The biggest number in the list is " << *maxPointer << " and its address is " << maxPointer  << std::endl;
    return 0;
}