#include <iostream>
#include <string>
#include <vector>

std::vector<int> unique(int[], int);

int main(int argc, char *args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    std::vector<int> filteredNumbers;
    filteredNumbers = unique(numbers, sizeof(numbers) / sizeof(numbers[0]));

    for (int i = 0; i < filteredNumbers.size(); i++) {
        std::cout << filteredNumbers.at(i) << " ";
    }
    //  should print: `[1, 11, 34, 52, 61]`


    return 0;
}

std::vector<int> unique(int numbers[], int size) {
    std::vector<int> returnList;
    for (int i = 0; i < size; i++) {
        bool hasValue = false;
        for (int j = 0; j < returnList.size(); j++) {
            if (numbers[i] == returnList[j]) {
                hasValue = true;
            }
        }
        if (!hasValue) {
            returnList.push_back(numbers[i]);
        }
    }
    return returnList;
}
