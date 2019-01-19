#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int numberToGuess = 51;
    int userInput;
    bool gameOn = true;
    std::cout << "Let's play guess the number!" << std::endl;
    std::cout << "Type in a number between 1 and 100:" << std::endl;
    while (gameOn) {
        std::cin >> userInput;
        if (userInput < numberToGuess) {
            std::cout << "The stored number is higher!" << std::endl;
        } else if (userInput > numberToGuess) {
            std::cout << "The stored number is lower!" << std::endl;
        } else {
            std::cout << "YES! Your guess is correct! Well done!" << std::endl;
            gameOn = false;
        }
    }

    return 0;
}