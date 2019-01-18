#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    int userInput;
    std::string pattern;
    std::cout << "Please provide me a number:(int)" << std::endl;
    std::cin >> userInput;

    for (int i = 1; i < userInput + 1; i++) { // number of lines = userInput, number of stars = i + i-1
        for (int j = userInput - i; j > 0; j--) {
            std::cout << " ";
        }
        for (int j = 0; j < i + (i - 1); j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}