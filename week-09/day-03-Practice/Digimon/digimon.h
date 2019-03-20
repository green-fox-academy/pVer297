//
// Created by Egri Zoltán on 2019. 03. 20..
//

#ifndef DIGIMON_DIGIMON_H
#define DIGIMON_DIGIMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    BABY,
    IN_TRAINING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA
} Digivolution;

typedef struct
{
    char name[128];
    int age : 8;
    int health : 8;
    char tamer_name[256];
    Digivolution level;
} digimon_t;

void generateTestArray(digimon_t* digiArray, int arraySize);
void printData(digimon_t* digiArray, int arraySize);
char* levelToString(Digivolution level);
int getMinHealth(digimon_t* digiArray, int arraySize);
int getLevelCount(digimon_t* digiArray, int arraySize, Digivolution level);
int getDigimonCount(digimon_t* digiArray, int arraySize, char* tamerName);
double getAvgHealth(digimon_t* digiArray, int arraySize, char* tamerName);
#endif //DIGIMON_DIGIMON_H
