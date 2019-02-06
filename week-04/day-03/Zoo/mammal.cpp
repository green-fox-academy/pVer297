//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "mammal.h"
Mammal::Mammal(std::string name)
{
    _name = name;
    _numberOfLimbs = 4;
    _age = rand() % 70;
    _gender = Gender(rand()%2);
}
std::string Mammal::getName()
{
    return _name;
}
std::string Mammal::breed()
{
    return "pushing miniature versions out.";
}
