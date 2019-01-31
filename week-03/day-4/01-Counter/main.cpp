#include <iostream>

// Write a recursive function that takes one parameter: n and counts down from n.

int countDown(int n)
{
    if (n < 1) return 0;
    std::cout << "Number: " << n << std::endl;
    return countDown(n - 1);
}

int main()
{
    countDown(99);
    return 0;
}