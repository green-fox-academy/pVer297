#include <iostream>

// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).

int sumDigit(int n)
{
    if (n <= 0) return 0;
    return n % 10 + sumDigit(n / 10);
}

int main()
{
    std::cout << "What number do you want to split up and calculate?" << std::endl;

    int userInput;
    std::cin >> userInput;
    std::cout << "The sum of the digits is: " << sumDigit(userInput) << std::endl;
    return 0;
}