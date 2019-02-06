//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "reptile.h"
Reptile::Reptile(std::string name)
{
    _name = name;
    _numberOfLimbs = 4;
    _age = rand() % 20;
    _gender = Gender(rand()%2);
}
std::string Reptile::getName()
{
    return _name;
}
std::string Reptile::breed()
{
    return "laying eggs.";
}
