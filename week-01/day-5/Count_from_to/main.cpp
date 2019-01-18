#include <iostream>

int main(int argc, char *args[]) {

    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5
    int userInput1;
    int userInput2;
    std::cout << "Please provide me two number:(int)" << std::endl;
    std::cin >> userInput1;
    std::cin >> userInput2;
    if (userInput1 > userInput2) {
        std::cout << "The second number should be bigger" << std::endl;
    } else {
        for (int i = userInput1; i <= userInput2; i++) {
            std::cout << i << std::endl;
        }
    }


    return 0;
}