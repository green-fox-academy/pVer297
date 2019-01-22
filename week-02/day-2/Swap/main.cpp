#include <iostream>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;

    int *aPoint = &a;
    int *bPoint = &b;

    std::cout << a << " " << b << std::endl;
    swap(aPoint, bPoint);
    std::cout << a << " " << b << std::endl;
    return 0;
}