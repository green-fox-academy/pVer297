//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "bird.h"
Bird::Bird(std::string name)
{
    _name = name;
    _numberOfLimbs = 4;
    _age = rand() % 70;
    _gender = Gender(rand()%2);
}
std::string Bird::getName()
{
    return _name;
}
std::string Bird::breed()
{
    return "laying eggs.";
}
