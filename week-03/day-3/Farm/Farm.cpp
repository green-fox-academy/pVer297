//
// Created by Egri Zoltán on 2019. 01. 30..
//

#include "Farm.h"

Farm::Farm(int freePlaces_)
{
    freePlaces = freePlaces_;
}

Farm::Farm(int freePlaces_, std::vector<Animal> *animals)
{
    freePlaces = freePlaces_;
    animalsInFarm = animals;
}

void Farm::breed()
{
    if (freePlaces > animalsInFarm->size()) {
        animalsInFarm->push_back(Animal());
        std::cout << "Yay, baby animals!" << std::endl;
    } else {
        std::cout << "The farm is too crowded, free up some space" << std::endl;
    }
}

void Farm::slaughter()
{
    if (animalsInFarm->empty()) {
        std::cout << "No animals left in the farm" << std::endl;
    } else {
        int minHunger = animalsInFarm->at(0).getHunger();
        unsigned int minHungerIndex = 0;
        for (unsigned int i = 0; i < animalsInFarm->size(); i++) {
            if (animalsInFarm->at(i).getHunger() < minHunger) {
                minHunger = animalsInFarm->at(i).getHunger();
                minHungerIndex = i;
            }
        }
        std::cout << "You slaughtered your healthiest animal!" << std::endl;
        int meat = 250 - (animalsInFarm->at(minHungerIndex).getHunger() * 2);
        std::cout << "You got " << meat << "kg meat" << std::endl;
        animalsInFarm->erase(animalsInFarm->begin() + minHungerIndex);
    }
}

int Farm::getNumberOfAnimals()
{
    return animalsInFarm->size();
}