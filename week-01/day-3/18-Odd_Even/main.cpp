#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.

    std::cout << "Pleas provide me a number:(integer)" << std::endl;
    int userInput;
    std::cin >> userInput;
    if((userInput % 2) == 0){
        std::cout << "The number is Even!";
    }else{
        std::cout << "The number is Odd!";
    }

    return 0;
}