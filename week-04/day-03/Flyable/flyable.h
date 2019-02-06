//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef FLYABLE_FLYABLE_H
#define FLYABLE_FLYABLE_H

class Flyable
{
 protected:
    bool _isInAir;
 public:
    virtual void land() = 0;
    virtual void fly() = 0;
    virtual void takeOff() = 0;
};

#endif //FLYABLE_FLYABLE_H
