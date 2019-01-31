#include <iostream>

// Create a recursive function called `refactorio`
// that returns it's input's factorial

int refactorio(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return num * refactorio(num - 1);
    }
}

int main() {
    std::cout << refactorio(10) << std::endl;
    return 0;
}