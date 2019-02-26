//
// Created by Egri Zoltán on 2019. 02. 26..
//

#ifndef INC_06_CAR_REGISTER_CARREGISTER_H
#define INC_06_CAR_REGISTER_CARREGISTER_H

#define CURRENT_YEAR 2019

#include <stdio.h>

enum Transmission
{
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
};

typedef struct
{
    char manufacturer[256];
    float price;
    int productionYear;
    enum Transmission trnsmType;
} car_t;

int getOlderCarsThan(car_t* cars, int arrayLength, int age);
int getTransmissionCount(car_t* cars, int arrayLength, enum Transmission trnsm);
void printInfo(car_t* cars, int arrayLength);
char* getTrnsmType(enum Transmission trnsm);

#endif //INC_06_CAR_REGISTER_CARREGISTER_H
