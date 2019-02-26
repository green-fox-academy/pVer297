//
// Created by Egri Zoltán on 2019. 02. 26..
//

#include "fileIO.h"

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

void loadPhones(const char* filename, smartphone_t* phones, int numOfPhones)
{
    FILE* fptr;
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        puts("Unable to load file");
        return;
    }
    for (int i = 0; i < numOfPhones; i++) {
        char name[256];
        int year = 0;
        int size = 0;

        fscanf(fptr, "%256s %d %d", name, &year, &size);

        strcpy(phones[i].name, name);
        phones[i].releaseYear = year;
        phones[i].size = getSize(size);
    }
    fclose(fptr);
}
void generatePriceList(const char* filename, smartphone_t* phones, int numOfPhones)
{
    FILE* fptr;
    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        puts("Unable to create/modify file");
        return;
    }

    for (int i = 0; i < numOfPhones; i++)
        fprintf(fptr, "%s %d$\n", phones[i].name, calculatePrice(phones[i]));

    fclose(fptr);
    puts("Success!");
}
