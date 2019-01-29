//
// Created by Egri Zoltán on 2019. 01. 29..
//

#ifndef PETROL_STATION_STATION_H
#define PETROL_STATION_STATION_H

#include <iostream>
#include "car.h"

class Station
{
 public:
    Station(int initGas);

    void fill(Car& carToFill);

 private:
    int gasAmount;
};

#endif //PETROL_STATION_STATION_H
