#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    std::ifstream myFile("my-file.txt");
    std::string text;
    while (getline(myFile, text)) {
        std::cout << text << std::endl;
    }
    myFile.close();
    return 0;
}