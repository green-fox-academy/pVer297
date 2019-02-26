#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int countLines(const char* filename)
{
    FILE* fptr;
    fptr = fopen(filename, "r");
    int count = 0;

    if (fptr == NULL)
        return 0;

    char line[256];
    while (fgets(line, sizeof(line), fptr)) {
        count++;
    }

    fclose(fptr);

    return count;
}

int main()
{
    char* file = "my-file.txt";
    printf("The file \'%s\' contains %d lines\n", file, countLines(file));
    return 0;
}