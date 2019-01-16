#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one
    float input1, input2;
    std::cout << "Please provide me two numbers:" << std::endl;
    std::cin >> input1;
    std::cin >> input2;
    if(input1 > input2) {
        std::cout << input1 << " is bigger!" << std::endl;
    } else {
        std::cout << input2 << " is bigger!" << std::endl;
    }

    return 0;
}