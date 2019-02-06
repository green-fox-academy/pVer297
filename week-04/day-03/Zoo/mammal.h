//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H

#include "animal.h"

class Mammal : public  Animal
{
 public:
    Mammal(std::string name);
    std::string getName() override;
    std::string breed() override;
};

#endif //ZOO_MAMMAL_H
