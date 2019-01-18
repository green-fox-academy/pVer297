#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.

    for (int i = 0; i <= 100; i++) {
        if ((i % 3) == 0) {
            std::cout << "Fizz";
        }
        if ((i % 5) == 0) {
            std::cout << "Buzz";
        }
        if ((i % 5) != 0 && (i % 3) != 0) {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    return 0;
}