#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stringFunctions.h"

#define MAX_WORD_LENGTH 45
#define MAX_WORD_COUNT 512

// Find the most common word in file.txt
// You need to make sure that characters like commas, colons, etc are not part of the words.
// Also make it case sensitive so words that only different in case sensitivity are the same.

typedef struct
{
    int hashVal;
    int word_length;
    char word[MAX_WORD_LENGTH];
} word_t;

typedef struct
{
    int numOfWords;
    word_t words[MAX_WORD_COUNT];
} text_t;

void loadWords(const char* filename, text_t* text)
{
    FILE* fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        puts("Unable to load file");
        return;
    }
    char* delimeters = " \n\"!?:;,.";
    char currentLine[512];
    int index = 0;

    while (fgets(currentLine, sizeof(currentLine), fptr)) {
        char* token = strtok(currentLine, delimeters);
        while (token) {
            toLower(token);
            strcpy(text->words[index].word, token);
            text->words[index].word_length = strlen(token);
            token = strtok(NULL, delimeters);
            index++;
        }
    }
    text->numOfWords = index;
}

void hash_text(text_t* text)
{

    for (int i = 0; i < text->numOfWords; i++) {
        int hash = 0;
        for (int j = 0; j < text->words[i].word_length; j++) {
            hash += (int) pow(151, text->words[i].word_length - (j + 1)) * text->words[i].word[j];
            hash %= text->numOfWords;
        }
        text->words[i].hashVal = hash;
    }
}

int main()
{
    char* filename = "file.txt";
    text_t USA;
    loadWords(filename, &USA);
    hash_text(&USA);
    int wordNumbers[MAX_WORD_COUNT] = {0};

    for (int i = 0; i < USA.numOfWords; i++) {
        wordNumbers[USA.words[i].hashVal]++;
    }

    int most_used_word = 0;
    int word_index = 0;
    for (int i = 0; i < USA.numOfWords; i++) {
        if (most_used_word < wordNumbers[i]) {
            most_used_word = wordNumbers[i];
            word_index = i;
        }
    }

    for (int i = 0; i < USA.numOfWords; i++) {
        if (USA.words[i].hashVal == word_index) {
            printf("The most used word is '%s'\n", USA.words[i].word);
            break;
        }
    }
    return 0;
}