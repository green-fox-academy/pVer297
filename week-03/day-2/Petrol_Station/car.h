//
// Created by Egri Zoltán on 2019. 01. 29..
//

#ifndef PETROL_STATION_CAR_H
#define PETROL_STATION_CAR_H

#include <iostream>

class Car
{
 public:
    Car(int initGas, int tankCapacity);

    bool isFull();
    void fill();

 private:
    int gasAmount;
    int capacit;
};

#endif //PETROL_STATION_CAR_H
