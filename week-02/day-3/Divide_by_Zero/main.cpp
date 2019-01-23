#include <iostream>
#include <fstream>

int main()
{
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0
    std::cout << "Please provide me a number:" << std::endl;
    int userInput;
    double result = 0;
    std::cin >> userInput;

    try {
        if (!(userInput < 0 || userInput > 0)) {
            throw 2;
        }
        result = 10.0 / userInput;
        std::cout << "The result is: " << result << std::endl;
    } catch (...) {
        std::cout << "You can't divide with that!"  << std::endl;
    }

    return 0;
}