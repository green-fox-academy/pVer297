#include <iostream>

// Given a string, compute recursively a new string where all the 'x' chars have been removed.

std::string removeX(std::string input){
    int foundX = input.find('x');
    if(foundX == std::string::npos) return input;
    return removeX(input.erase(foundX,1));
}

int main() {
    std::string xString = "xxxxeroxingxxx";
    std::cout << xString << std::endl;
    std::cout << removeX(xString) << std::endl;
    return 0;
}