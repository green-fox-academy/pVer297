#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int* pointer = NULL;
    int arrSize = 10;
    pointer = (int*) malloc(sizeof(int) * arrSize);

    for (int i = 0; i < arrSize * 2; i += 2)
        pointer[i / 2] = i;

    for (int i = 0; i < arrSize; i++)
        printf("%d\n", pointer[i]);

    realloc(pointer, 0);
    return 0;
}