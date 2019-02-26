//
// Created by Egri Zoltán on 2019. 02. 26..
//

#ifndef INC_11_SMARTPHONES_PHONEREGISTER_H
#define INC_11_SMARTPHONES_PHONEREGISTER_H

#define CURRENT_YEAR 2019

#include <stdio.h>

enum ScreenSize
{
    BIG,
    MEDIUM,
    SMALL
};

typedef struct
{
    char name[256];
    int releaseYear;
    enum ScreenSize size;
} smartphone_t;

char* getOldestPhone(smartphone_t* phones, int arraySize);
int getScreenSizeCount(smartphone_t* phones, int arraySize, enum ScreenSize size);
int calculatePrice(smartphone_t phone);
enum ScreenSize getSize(int size);
void printInfo(smartphone_t* phones, int arrayLength);
char* sizeToString(enum ScreenSize size);

#endif //INC_11_SMARTPHONES_PHONEREGISTER_H
