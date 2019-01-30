//
// Created by Egri Zoltán on 2019. 01. 30..
//

#ifndef FARM_FARM_H
#define FARM_FARM_H

#include "Animal.h"
#include <iostream>
#include <vector>

class Farm
{
 private:
    int freePlaces;
    std::vector<Animal> *animalsInFarm;
 public:
    Farm(int freePlaces_);
    Farm(int freePlaces_, std::vector<Animal> *animals);
    void breed();
    void slaughter();
    int getNumberOfAnimals();
};

#endif //FARM_FARM_H
