#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful


bool copyContent(std::string sourceFile, std::string targetFile) {
    try {
        std::ifstream fileToRead(sourceFile); //read file
        if (!fileToRead.is_open()) {
            throw 1;
        }
        std::ofstream fileToWrite(targetFile); //write file
        if (!fileToWrite.is_open()) {
            throw 1;
        }
        std::string fileContent; //string containing the current row

        while(getline(fileToRead,fileContent)){
            fileToWrite << fileContent << std::endl;
        }
        return true;
    } catch (...) {
        return false;
    }
}

int main() {
    std::cout << "Please type in the name of the source file and the name of the target file:" << std::endl;
    std::string copyFrom;
    std::string copyTo;

    std::cin >> copyFrom >> copyTo;

    std::string output = copyContent(copyFrom, copyTo) ? "Success" : "Failure";
    std::cout << output << std::endl;
    return 0;
}