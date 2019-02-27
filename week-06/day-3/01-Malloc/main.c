#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits


int main()
{
    int* pointer = NULL;
    int arrSize = 10;
    pointer = (int*) malloc(sizeof(int) * arrSize);

    for (int i = 0; i < 5; i++) {
        pointer[i] = i;
    }

    for (int i = 0; i < arrSize; i++) {
        printf("%d\n", pointer[i]); //here goes the garbage, yay
    }

    free(pointer);
    return 0;
}