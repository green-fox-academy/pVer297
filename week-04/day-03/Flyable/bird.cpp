//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "bird.h"
Bird::Bird(std::string name)
{
    _name = name;
    _numberOfLimbs = 4;
    _age = rand() % 70;
    _gender = Gender(rand() % 2);
    _isInAir = false;
}
std::string Bird::getName()
{
    return _name;
}
std::string Bird::breed()
{
    return "laying eggs.";
}
void Bird::takeOff()
{
    if (!_isInAir) {
        std::cout << "The bird took off" << std::endl;
        _isInAir = true;
    } else {
        std::cout << "The bird is already in air" << std::endl;
    }
}
void Bird::fly()
{
    if (!_isInAir) {
        std::cout << "The bird is not in the air" << std::endl;
    } else {
        std::cout << "The bird is flying" << std::endl;
    }
}
void Bird::land()
{
    if (!_isInAir) {
        std::cout << "The bird is already on the ground" << std::endl;
    } else {
        std::cout << "The bird landed on the ground" << std::endl;
        _isInAir = false;
    }
}

void Bird::info()
{
    std::string flyState = _isInAir ? " It's in the air." : " It's on the ground.";
    std::cout << _name << " is a " << _age << " years old "
              << genderToString(_gender) << " bird."
              << flyState << std::endl;
}