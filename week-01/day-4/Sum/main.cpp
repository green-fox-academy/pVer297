#include <iostream>
#include <string>

int sum(int);

int main(int argc, char* args[]) {

    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer
    std::cout << "Please provide me an input:(integer)" << std::endl;
    int userInput;
    std::cin >> userInput;
    std::cout << "Your number was " << userInput << std::endl;
    std::cout << "The sum of numbers before that is " << sum(userInput) << std::endl;

    return 0;
}

int sum(int input){
    int sumOfNumbers = 0;
    for(int i = 0;i<=input;i++){
        sumOfNumbers += i;
    }
    return sumOfNumbers;
}