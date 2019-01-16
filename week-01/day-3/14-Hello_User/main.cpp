#include <iostream>

int main(int argc, char* args[]) {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::string userInput;

    std::cout << "Hi. What's your name?" << std::endl;
    std::cin >> userInput;
    std::cout << "Hello " << userInput <<"!" << std::endl;

    return 0;
}