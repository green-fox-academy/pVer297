#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was
    int userInput;
    std::cout << "Please provide me a number:(int)" << std::endl;
    std::cin >> userInput;
    for (int i = 0; i < userInput; i++) { //line loop
        for (int j = 0; j < userInput; j++) { //position loop
            if (i % (userInput - 1) == 0) { //first and last line
                std::cout << "%";
            } else if (j == 0 || j == userInput - 1 || j == i) { //first and last character
                std::cout << "%";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }


    return 0;
}