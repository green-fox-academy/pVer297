//
// Created by Egri Zoltán on 2019. 02. 26..
//

#include "carRegister.h"

int getOlderCarsThan(car_t* cars, int arrayLength, int age)
{
    int count = 0;
    for (int i = 0; i < arrayLength; i++) {
        int carAge = CURRENT_YEAR - cars[i].productionYear;
        if (carAge > age)
            count++;
    }
    return count;
}
int getTransmissionCount(car_t* cars, int arrayLength, enum Transmission trnsm)
{
    int count = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (cars[i].trnsmType == trnsm)
            count++;
    }
    return count;
}
void printInfo(car_t* cars, int arrayLength)
{
    printf("There is %d cars in the list:\n", arrayLength);
    for (int i = 0; i < arrayLength; i++) {
        printf("%d: %s\n\tPrice: %.0f, Year: %d, Transmission: %s\n",
               i + 1,
               cars[i].manufacturer,
               cars[i].price,
               cars[i].productionYear,
               getTrnsmType(cars[i].trnsmType));
    }
}
char* getTrnsmType(enum Transmission trnsm)
{
    switch (trnsm) {
        case AUTOMATIC: return "Automatic";
        case MANUAL: return "Manual";
        case CVT: return "CVT";
        case SEMI_AUTOMATIC: return "Semi-Automatic";
        case DUAL_CLUTCH: return "Dual-Clutch";
    }
}

