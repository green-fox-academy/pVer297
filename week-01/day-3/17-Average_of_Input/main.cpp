#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    float num1,num2,num3,num4,num5;
    std::cout << "Please provide me five numbers:" << std::endl;
    std::cin >> num1;
    std::cin >> num2;
    std::cin >> num3;
    std::cin >> num4;
    std::cin >> num5;

    float sum = num1 + num2 + num3 + num4 +num5;
    float average = sum/5;

    std::cout << "Sum: " << sum << ", Average: " << average << std::endl;

    return 0;
}