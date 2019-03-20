#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'

int findFirstLastDiff(char* string, char letter)
{
    int index = 0;
    int firstPos = -1;
    int lastPos = -1;
    int reachedEnd = 0;
    while (index >= 0) {
        if (!string[index]) {
            reachedEnd = 1;
        }

        if (string[index] == letter && firstPos < 0) {
            firstPos = index;
        } else if (string[index] == letter && lastPos < 0 && reachedEnd) {
            lastPos = index;
        }

        if (!reachedEnd) {
            index++;
        } else {
            index--;
        }

    }
    return (lastPos - firstPos);
}

int main()
{
    char str[] = "This is a sample string";
    char charToFind = 's';
    printf("%s\n", str);
    printf("The distance between the first and last occurrence of '%c' is %d\n",
           charToFind,
           findFirstLastDiff(str, charToFind));

    return 0;
}