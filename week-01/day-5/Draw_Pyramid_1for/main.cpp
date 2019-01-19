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
    std::cout << "Please provide me a number:(int)" << std::endl;
    std::cin >> userInput;
    int currentLine = 0;
    int linePos = 1;
    for (int i = 0; i <= (userInput * userInput)*2; i++) {
        if (linePos < userInput - currentLine || linePos > userInput + currentLine) {
            std::cout << " ";
        } else {
            std::cout << "*";
        }
        if (i % (userInput*2) == 0 && i > 0) {
            std::cout << std::endl;
            currentLine++;
            linePos = 0;
        }
        linePos++;
    }

    return 0;
}