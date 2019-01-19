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

    for (int i = 0; i < userInput; i++) {
        for (int j = 0; j <= userInput * 2; j++) {
            if (j < userInput - i || j > userInput + i) {
                std::cout << " ";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}