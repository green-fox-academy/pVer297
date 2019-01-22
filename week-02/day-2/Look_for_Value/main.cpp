#include <iostream>

int valueSearcher(int *list, int size, int toSearchFor) {
    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        if(list[i] == toSearchFor){
            foundIndex = i;
        }
    }
    return foundIndex;
}

int main() {
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0
    int numbers[10] = {5, 10, 15, 7, 14, 21, 2, 4, 6, 20};
    int numberToSearch;

    std::cout << "What number are you looking for?" << std::endl;
    std::cin >> numberToSearch;
    int foundIndex = valueSearcher(numbers, sizeof(numbers) / sizeof(numbers[0]), numberToSearch);
    if(foundIndex >= 0){
        std::cout << "The " << numberToSearch << " is in the list at index " << foundIndex << std::endl;
    } else {
        std::cout << "No such number in the list, sorry" << std::endl;
    }
    return 0;
}