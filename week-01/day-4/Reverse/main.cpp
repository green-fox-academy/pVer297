#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[] = {3, 4, 5, 6, 7};
    int sizeOfList = sizeof(aj)/sizeof(aj[0]);

    for(int i = 0;i<sizeOfList;i++){
        std::cout << aj[i] << " ";
    }

    std::cout << std::endl;

    for(int i = 0;i<sizeOfList/2;i++){
        int temp = aj[i];
        aj[i] = aj[sizeOfList-i-1];
        aj[sizeOfList-i-1] = temp;
    }

    for(int i = 0;i<sizeOfList;i++){
        std::cout << aj[i] << " ";
    }

    return 0;
}