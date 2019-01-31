#include <iostream>

// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).

int powerN(int base, int n)
{
    if (base < 1 || n < 1) return 1;
    return base * powerN(base, n - 1);
}

int main()
{
    std::cout << "What power do you want to calculate?" << std::endl;
    std::cout << "(base power)" << std::endl;
    int baseInput, powerInput;
    std::cin >> baseInput >> powerInput;
    std::cout << baseInput << " to the power of " << powerInput << " is: ";
    std::cout << powerN(baseInput, powerInput) << std::endl;
    return 0;
}