#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    int numberOfInputs;
    float sumOfNumbers = 0;
    std::cout << "How many numbers do you want to add together?" << std::endl;
    std::cin >> numberOfInputs;
    std::cout << "Type in the numbers:" << std::endl;
    for (int i = 0; i < numberOfInputs; i++) {
        float input;
        std::cin >> input;
        sumOfNumbers += input;
    }

    std::cout << "Sum: " << sumOfNumbers << ", Average: " << sumOfNumbers/numberOfInputs << std::endl;

    return 0;
}