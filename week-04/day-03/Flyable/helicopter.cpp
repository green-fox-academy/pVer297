//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "helicopter.h"
Helicopter::Helicopter(int maxSpeed, int weight)
{
    _maxSpeed = maxSpeed;
    _weight = weight;
    _speed = 0;
    _isInAir = false;
}
void Helicopter::takeOff()
{
    if (!_isInAir) {
        std::cout << "The helicopter took off" << std::endl;
        _isInAir = true;
    } else {
        std::cout << "The helicopter is already in air" << std::endl;
    }
}
void Helicopter::fly()
{
    if (!_isInAir) {
        std::cout << "The helicopter is not in the air" << std::endl;
    } else {
        if (_speed <= _maxSpeed - 20) {
            std::cout << "The helicopter is flying faster" << std::endl;
            _speed += 20;
        } else {
            std::cout << "The helicopter is already at its max speed" << std::endl;
        }
    }
}
void Helicopter::land()
{
    if (!_isInAir) {
        std::cout << "The helicopter is already on the ground" << std::endl;
    } else {
        std::cout << "The helicopter landed on the ground" << std::endl;
        _isInAir = false;
        _speed = 0;
    }
}

void Helicopter::info()
{
    std::string flyState = _isInAir ? " It's in the air." : " It's on the ground.";
    std::cout << "This is a " << _weight << " kg helicopter capable of reaching "
              << _maxSpeed << " km/h. It's current speed is " << _speed  << ". "
              << flyState << std::endl;
}