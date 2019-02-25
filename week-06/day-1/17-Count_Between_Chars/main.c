#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeatingChars(char* string){
    int lastSeen[128] = {0};
    int index = 0;
    int maxInterval = 0;
    while(string[index]){
        if(lastSeen[string[index]] != 0){
            int interval = index - lastSeen[string[index]];
            if(interval > maxInterval) {
                maxInterval = interval;
            }
        } else {
            lastSeen[string[index]] = index+1;
        }
        index++;
    }
    return maxInterval;
}

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d",repeatingChars(word));

    return 0;
}