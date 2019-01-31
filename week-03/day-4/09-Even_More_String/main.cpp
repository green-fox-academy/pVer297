#include <iostream>

// Given a string, compute recursively a new string where all the
// adjacent chars are now separated by a '*'.

std::string placeStar(std::string input, int index = 1)
{
    if (index > input.size()-1) return input;
    return placeStar(input.insert(index, 1, '*'), index + 2);
}

int main()
{
    std::cout << placeStar("abcdefghijklmnop") << std::endl;
    return 0;
}