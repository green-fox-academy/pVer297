#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number paramter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"

void writeToFile(std::string nameOfFile, std::string input, int numberOfLines) {
    std::ofstream fileToWrite;
    fileToWrite.open(nameOfFile);
    if (fileToWrite.is_open() && numberOfLines > 0) {
        for (int i = 0; i < numberOfLines; i++) {
            fileToWrite << input << std::endl;
        }
        std::cout << "Write done!" << std::endl;
    } else {
        std::cout << "Couldn't write file" << std::endl;
    }
}

int main() {

    std::cout << "File to write - Input to file - Number of lines to write (separated by spaces)" << std::endl;
    std::string nameOfFile;
    std::string input;
    int numberOfLines;
    std::cin >> nameOfFile >> input >> numberOfLines;

    writeToFile(nameOfFile, input, numberOfLines);
    return 0;
}