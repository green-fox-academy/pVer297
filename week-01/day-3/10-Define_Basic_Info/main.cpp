#include <iostream>

int main(int argc, char* args[]) {

    // Define several things as a variable then print their values
    // Your name as a string
    // Your age as an integer
    // Your height in meters as a double
    // Whether you are married or not as a boolean

    std::string myName = "Zoltan Egri";
    int myAge = 21;
    double myHeight = 1.95;
    bool married = false;

    std::cout << "My name is " << myName << ". I'm " << myAge << " years old." << std::endl;
    std::cout << "My height is " << myHeight << "m." << std::endl;
    std::cout << "Am I married? : " << married << std::endl;

    return 0;
}