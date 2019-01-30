//
// Created by Egri Zoltán on 2019. 01. 30..
//

#include "Animal.h"

Animal::Animal()
{
    hunger = 50;
    thirst = 50;
}

void Animal::eat()
{
    hunger--;
}

void Animal::drink()
{
    thirst--;
}

void Animal::play()
{
    hunger++;
    thirst++;
}

int Animal::getHunger()
{
    return hunger;
}