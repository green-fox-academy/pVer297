#include <iostream>

// Given a string, compute recursively (no loops) a new string where all the
// lowercase 'x' chars have been changed to 'y' chars.

std::string replaceX(std::string input){
    int foundX = input.find('x');
    if(foundX == std::string::npos) return input;
    return replaceX(input.replace(foundX, 1,"y"));
}

int main() {
    std::string xString = "xeroxing";
    std::cout << xString << std::endl;
    std::cout << replaceX(xString) << std::endl;
    return 0;
}