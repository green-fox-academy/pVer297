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
    while (currentWord) {
        if (strcmp(word, currentWord) == 0) {
            return 1;
        }
        currentWord = strtok(NULL, " .\n");
    }
    return 0;
}

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return 1 if the given sentence contains the given word
    // and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char* word = "apple";
    char sentence[38] = "An apple a day keeps the doctor away.";

    // the output should be: 1
    if(isInSentence(sentence, word)){
        puts("The word is in the sentence");
    } else {
        puts("The sentence does not contain the word");
    }

    return 0;
}