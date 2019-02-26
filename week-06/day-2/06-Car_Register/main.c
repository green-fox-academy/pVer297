#include <string.h>
#include <stdio.h>
#include "carRegister.h"

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

int main()
{
    car_t cars[10] = {{"Volkswagen", 16500, 2011, MANUAL},
                      {"Suzuki", 10000, 2008, SEMI_AUTOMATIC},
                      {"Audi", 28000, 2016, AUTOMATIC},
                      {"Lamborghini", 320000, 2018, DUAL_CLUTCH},
                      {"Koenigsegg", 2000000, 2019, CVT},
                      {"Ford", 21400, 2018, MANUAL},
                      {"Subaru", 3500, 2001, MANUAL},
                      {"BMW", 6000, 2005, SEMI_AUTOMATIC},
                      {"SEAT", 4800, 2006, AUTOMATIC},
                      {"Opel", 1600, 2002, MANUAL}};
    int numOfCars = sizeof(cars) / sizeof(cars[0]);

    printInfo(cars, numOfCars);
    printf("\nThere is %d cars older than 5 years\n", getOlderCarsThan(cars, numOfCars, 5));
    printf("\nThere is %d cars with manual transmission\n", getTransmissionCount(cars, numOfCars, MANUAL));
    return 0;
}