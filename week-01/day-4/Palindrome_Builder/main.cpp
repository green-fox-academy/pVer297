#include <iostream>
#include <string>

std::string buildPalindrome(std::string);

int main() {
    std::string userInput;
    std::cout << "Type in something: " << std::endl;
    std::cin >> userInput;
    std::cout << buildPalindrome(userInput) << std::endl;

    system("PAUSE");
    return 0;
}


std::string buildPalindrome(std::string input){
    std::string reverseString;
    for(int i = 0; i < input.size();i++){
        reverseString += input[input.size()-i-1];
    }
    return input+reverseString;
}