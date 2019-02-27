#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

int countLength(const char* string)
{
    int index = 0;
    while (string[index])
        index++;
    return index;
}

char* concatString(char* dest, char* src)
{
    int srcCount = countLength(src);
    int destCount = countLength(dest);

    dest = (char*) realloc(dest, sizeof(char) * (srcCount + destCount) + 1);
    memcpy(dest + destCount, src, sizeof(char) * srcCount + 1);
    return dest;
}

char* repeatString(char* string, int num)
{
    char* tmp = (char*) malloc(sizeof(char) * countLength(string) + 1);
    strcpy(tmp, string);
    for (int i = 0; i < num - 1; i++) {
        string = concatString(string, tmp);
    }
    free(tmp);
    return string;
}

int main()
{
    char* apple = (char*) malloc(sizeof(char) * countLength("Apple") + 1);
    strcpy(apple, "Apple");

    puts(repeatString(apple, 5));
    free(apple);
    return 0;
}