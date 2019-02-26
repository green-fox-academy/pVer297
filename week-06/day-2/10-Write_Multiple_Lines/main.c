#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void writeFile(const char* filename, const char* word, int count)
{
    FILE* fptr;
    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        puts("Unable to create/modify file");
        return;
    }

    for (int i = 0; i < count; i++)
        fprintf(fptr, "%s\n", word);

    fclose(fptr);
    puts("Success!");
}

int main()
{
    writeFile("my-file.txt", "apple", 5);
    return 0;
}