#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toLower(char* string)
{
    int index = 0;
    while (string[index]) {
        if (string[index] < 91 && string[index] > 64)//char is uppercase
            string[index] += 32; //setting the char equal to its lowercase value
        index++;
    }
    return string;
}

int isInSentence(char* sentence, char* word)
{
    toLower(sentence);
    char* currentWord = strtok(sentence, " .\n");
    int index = 0;
    while (currentWord) {
        if (strcmp(word, currentWord) == 0) {
            return index;
        }
        currentWord = strtok(NULL, " .\n");
        index++;
    }
    return 0;
}

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return the index of the word in the sentence and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char* word = "doctor";
    char sentence[38] = "An apple a day keeps the doctor away.";

    // the output should be: 6
    int ret = isInSentence(sentence, word);
    if(ret){
        printf("The word is in the sentence at index %d", ret);
    } else {
        puts("The sentence does not contain the word");
    }

    return 0;
}