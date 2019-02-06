//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H

#include "animal.h"

class Bird : public  Animal
{
 public:
    Bird(std::string name);
    std::string getName() override;
    std::string breed() override;
};

#endif //ZOO_BIRD_H
