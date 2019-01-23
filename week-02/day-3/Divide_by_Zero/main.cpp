#include <iostream>
#include <fstream>


double divBy(double input){
    try {
        if (!(input < 0 || input > 0)) {
            throw 2;
        }
        return 10.0 / input;
    } catch (...) {
        std::cout << "You can't divide with that!"  << std::endl;
        return 0;
    }
}

int main()
{
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0
    std::cout << "Please provide me a number:" << std::endl;
    double userInput;
    std::cin >> userInput;

    std::cout << divBy(userInput) << std::endl;

    return 0;
}