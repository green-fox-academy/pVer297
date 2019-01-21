#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string quote("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");
    std::string searchString = "It you";
    std::string toInsert = "It always takes longer than you";

    // When saving this quote a disk error has occured. Please fix it.
    // Add "always takes longer than" to the quote between the words "It" and "you" using the replace function
    quote.replace(quote.find("It you"),searchString.length(),toInsert);
    std::cout << quote << std::endl;
    return 0;
}