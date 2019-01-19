#include <iostream>

int main(int argc, char *args[]) {

    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    int userInput;
    std::cout << "Please provide me a number:(int)" << std::endl;
    std::cin >> userInput;
    int startingChar = 0;
    for (int i = 1; i <= userInput * userInput; i++) { //line loop
        if (i % 2 == startingChar) {
            std::cout << "%";

        } else {
            std::cout << " ";
        }
        if (i % userInput == 0) {
            std::cout << std::endl;
            startingChar += 1-(startingChar*2);
        }
    }


    return 0;
}