#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it
    std::cout << "Hello, how many miles do you want to convert?(integer)" << std::endl;
    int userInput;
    std::cin >> userInput;
    double valueInKM = userInput * 1.609344;
    std::cout << userInput << " mile is " << valueInKM << " kilometer";
    return 0;
}