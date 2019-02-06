//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef ZOO_REPTILE_H
#define ZOO_REPTILE_H

#include "animal.h"

class Reptile : public  Animal
{
 public:
    Reptile(std::string name);
    std::string getName() override;
    std::string breed() override;
};

#endif //ZOO_REPTILE_H
