#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
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

int main()
{
    char* string1 = (char*) malloc(sizeof(char) * countLength("Lorem ipsum") + 1);
    char* string2 = (char*) malloc(sizeof(char) * countLength("Dolor sit amet") + 1);

    strcpy(string1, "Lorem ipsum");
    strcpy(string2, "Dolor sit amet");

    string1 = concatString(string1, string2);

    puts(string1);

    free(string1);
    free(string2);
    return 0;
}