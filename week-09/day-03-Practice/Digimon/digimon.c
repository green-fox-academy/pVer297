//
// Created by Egri Zoltán on 2019. 03. 20..
//

#include <time.h>
#include "digimon.h"

int getMinHealth(digimon_t* digiArray, int arraySize)
{
    if (digiArray == NULL || arraySize == 0)
        return -1;

    int minHP = digiArray[0].health;
    int minHPIndex = 0;
    for (int i = 1; i < arraySize; i++) {
        if (minHP > digiArray[i].health) {
            minHP = digiArray[i].health;
            minHPIndex = i;
        }
    }
    return minHPIndex;
}
int getLevelCount(digimon_t* digiArray, int arraySize, Digivolution level)
{
    if (digiArray == NULL || arraySize == 0)
        return -1;

    int count = 0;

    for (int i = 0; i < arraySize; i++) {
        if (digiArray[i].level == level)
            count++;
    }
    return count;
}
int getDigimonCount(digimon_t* digiArray, int arraySize, char* tamerName)
{
    if (digiArray == NULL || arraySize == 0)
        return -1;

    int count = 0;

    for (int i = 0; i < arraySize; i++) {
        if (strcmp(digiArray[i].tamer_name, tamerName) == 0)
            count++;
    }
    return count;
}
double getAvgHealth(digimon_t* digiArray, int arraySize, char* tamerName)
{
    if (digiArray == NULL || arraySize == 0)
        return -1;

    int count = 0;
    int hpSum = 0;

    for (int i = 0; i < arraySize; i++) {
        if (strcmp(digiArray[i].tamer_name, tamerName) == 0) {
            count++;
            hpSum += digiArray[i].health;
        }
    }
    return (float) hpSum / count;
}

void generateTestArray(digimon_t* digiArray, int arraySize)
{
    srand(time(0));
    if (digiArray == NULL || arraySize == 0)
        return;

    char* tamer_names[] = {"Master Tamer",
                           "Rookie Tamer",
                           "Joska Bacsi",
                           "xXxDigiMasterxXx",
                           "The Noob",
                           "John Doe",
                           "Jane Doe"};
    int numOfTamers = 7;

    char* digimon_names[] = {"Agumon",
                             "Gatomon",
                             "Palmon",
                             "Gabumon",
                             "Patamon",
                             "MoonMoon",
                             "Tentomon",
                             "Leomon"};
    int numOfDigimons = 8;

    for (int i = 0; i < arraySize; i++) {
        strcpy(digiArray[i].name, digimon_names[rand() % numOfDigimons]);
        digiArray[i].age = rand() % 46 + 5;
        digiArray[i].health = rand() % 81 + 20;
        strcpy(digiArray[i].tamer_name, tamer_names[rand() % numOfTamers]);
        digiArray[i].level = BABY + rand() % 6;
    }
}

void printData(digimon_t* digiArray, int arraySize)
{
    if (digiArray == NULL || arraySize == 0)
        return;

    for (int i = 0; i < arraySize; i++) {
        printf("Tamer: %s || Digimon: %s | HP: %d | Age: %d | Level: %s\n",
               digiArray[i].tamer_name,
               digiArray[i].name,
               digiArray[i].health,
               digiArray[i].age,
               levelToString(digiArray[i].level));
    }
}

char* levelToString(Digivolution level)
{
    switch (level) {
        case BABY: return "Baby";
        case IN_TRAINING: return "In Training";
        case ROOKIE: return "Rookie";
        case CHAMPION: return "Champion";
        case ULTIMATE: return "Ultimate";
        case MEGA: return "Mega";
    }
}