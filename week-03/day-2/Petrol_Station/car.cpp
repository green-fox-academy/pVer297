//
// Created by Egri Zoltán on 2019. 01. 29..
//

#include "car.h"

Car::Car(int initGas, int tankCapacity)
{
    gasAmount = initGas;
    capacit = tankCapacity;
}

bool Car::isFull()
{
    return gasAmount == capacit;
}

void Car::fill()
{
    gasAmount++;
}