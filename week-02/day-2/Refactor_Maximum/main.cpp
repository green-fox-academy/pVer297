#include <iostream>

int *min(int *list, int size) {
    int *minPointer = list;
    for (int i = 0; i < size; i++) {
        if (list[i] < *minPointer) {
            minPointer = list + i;
        }
    }
    return minPointer;
}

int *max(int *list, int size) {
    int *maxPointer = list;
    for (int i = 0; i < size; i++) {
        if (list[i] > *maxPointer) {
            maxPointer = list + i;
        }
    }
    return maxPointer;
}

int *lookFor(int *list, int size, int *(*search)(int *, int)) {
    int *returnPointer = nullptr;
    returnPointer = search(list, size);
    return returnPointer;
}

int main() {
    // Refactor time!
    // use your 'refactor_maximum.cpp', solve the same exercise by creating a separate function
    // for each functionality
    std::cout << "How many numbers do you want to compare?" << std::endl;
    int numberOfInputs;
    std::cin >> numberOfInputs;

    std::cout << "What do you want to find?(max/min)" << std::endl;
    std::string searchKey;
    std::cin >> searchKey;

    std::cout << "Please type in your numbers:" << std::endl;
    int inputArray[numberOfInputs];
    for (int i = 0; i < numberOfInputs; i++) {
        std::cin >> inputArray[i];
    }
    if (searchKey == "min") {
        std::cout << "The smallest number is: ";
        std::cout << *lookFor(inputArray, sizeof(inputArray) / sizeof(inputArray[0]), min) << std::endl;
    } else if (searchKey == "max") {
        std::cout << "The biggest number is: ";
        std::cout << *lookFor(inputArray, sizeof(inputArray) / sizeof(inputArray[0]), max) << std::endl;
    }

    return 0;
}