#include <iostream>
#include <string>
void factorio(int, int&);

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int output = 0;
    int userInput;
    std::cout << "Please provide me an input between 1 and 10: " << std::endl;
    std::cin >> userInput;
    std::cout << userInput << "! is:" << std::endl;
    factorio(userInput, output);
    std::cout << output << std::endl;
    return 0;
}

void factorio(int input, int& output){
    output = input;
    for(int i = input-1;i>0;i--){
        output *= i;
    }
}