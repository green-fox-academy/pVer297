#include <iostream>
#include <fstream>
#include <string>

int countLines(std::string filename) {
    std::ifstream myFile(filename);
    std::string content;
    int numberOfLines = 1;
    if (myFile.is_open()) {
        while (getline(myFile, content)) {
            numberOfLines++;
        }
        myFile.close();
        return numberOfLines;
    } else {
        return 0;
    }

}

int main() {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file
    std::string input;
    std::cout << "What file do you want to check?" << std::endl;
    std::cin >> input;

    std::cout << countLines(input) << std::endl;

    return 0;
}