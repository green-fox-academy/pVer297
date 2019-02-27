#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int* numbers = NULL;
    int* odd = NULL;
    int arrSize = 10;

    numbers = (int*) malloc(sizeof(int) * arrSize);
    odd = (int*) malloc(sizeof(int) * arrSize);

    for (int i = 0; i < arrSize * 2; i += 2) {
        numbers[i / 2] = i;
        odd[i / 2] = i + 1;
    }

    numbers = (int*) realloc(numbers, sizeof(int) * arrSize * 2);

    memcpy(numbers + arrSize, odd, sizeof(int) * arrSize);

    for (int i = arrSize * 2 - 1; i >= 0; i--)
        printf("%d\n", numbers[i]);

    free(numbers);
    free(odd);
    return 0;
}