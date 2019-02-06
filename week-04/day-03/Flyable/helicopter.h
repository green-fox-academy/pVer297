//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H

#include "flyable.h"
#include "vehicle.h"
#include <iostream>

class Helicopter : public Flyable, public Vehicle
{
 public:
    Helicopter(int maxSpeed, int weight);
    void takeOff() override;
    void fly() override;
    void land() override;

    void info();

};

#endif //FLYABLE_HELICOPTER_H
