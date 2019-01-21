#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> quoteSwap(std::vector<std::string> &quote, int firstWordToSwap, int secondWordToSwap) {
    std::swap(quote.at(firstWordToSwap),quote.at(secondWordToSwap));
    return quote;
}

int main(int argc, char *args[]) {
    std::vector<std::string> quote = {"What", "I", "do", "create,", "I", "cannot", "not", "understand."};

    // Accidentally I messed up this quote from Richard Feynman.
    // Two words are out of place
    // Your task is to fix it by swapping the right words with code
    // Create a method called quoteSwap().

    // Also, print the sentence to the output with spaces in between.

    quoteSwap(quote,2,5);
    for (int i = 0; i < quote.size(); i++) {
        std::cout << quote[i] << " ";
    }

    return 0;
}