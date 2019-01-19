#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was
    int userInput;
    std::cout << "Please provide me a number:(int)" << std::endl;
    std::cin >> userInput;
    int currentLine = 0;
    int linePos = 1;
    bool ascending = true;
    for (int i = 0; i <= (userInput * userInput) * 2; i++) {
        if (linePos < userInput - currentLine || linePos > userInput + currentLine) {
            std::cout << " ";
        } else {
            std::cout << "*";
        }
        if ((i >= userInput * userInput) && ascending) {
            ascending = false;
            if (userInput % 2 == 0) {
                currentLine++; //repeat the changing line if the input is even
            }
        }
        if (i % (userInput * 2) == 0 && i > 0) {
            std::cout << std::endl;
            if (ascending) {
                currentLine++;
            } else {
                currentLine--;
            }
            linePos = 0;
        }
        linePos++;
    }

    return 0;
}