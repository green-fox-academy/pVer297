#include <iostream>

int *lookForMin(int *list, int size) {
    int *minPointer = list;
    for (int i = 0; i < size; i++) {
        if (list[i] < *minPointer) {
            minPointer = list + i;
        }
    }
    return minPointer;
}

int main() {
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int *pointerToMin = nullptr;
    pointerToMin = lookForMin(numbers, sizeof(numbers) / sizeof(numbers[0]));
    std::cout << "The smallest number in the list is: " << *pointerToMin << " and its address is: " << pointerToMin;
    return 0;
}