//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H

#include "animal.h"
#include "flyable.h"

class Bird : public  Animal, public Flyable
{
 public:
    Bird(std::string name);
    std::string getName() override;
    std::string breed() override;
    void info();

    void takeOff() override;
    void fly() override;
    void land() override;
};

#endif //ZOO_BIRD_H
