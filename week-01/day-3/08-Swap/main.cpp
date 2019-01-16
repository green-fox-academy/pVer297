#include <iostream>

int main(int argc, char* args[]) {

    // Swap the values of the variables
    int a = 123;
    int b = 526;

    int temp = a;
    a = b;
    b = temp;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}