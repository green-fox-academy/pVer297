#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

int addNumbers(int n){
    if(n < 1) return 0;
    return n+addNumbers(n-1);
}

int main()
{
    std::cout << "To what point do you want to add numbers together?" << std::endl;

    int userInput;
    std::cin >> userInput;
    std::cout << "Numbers added 1 to " << userInput << ": " << addNumbers(userInput) << std::endl;
    return 0;
}