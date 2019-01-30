//
// Created by Egri Zoltán on 2019. 01. 30..
//

#ifndef FARM_ANIMALS_H
#define FARM_ANIMALS_H

class Animal
{
 private:
    int hunger;
    int thirst;
 public:
    Animal();
    void eat();
    void drink();
    void play();
    int getHunger();
};

#endif //FARM_ANIMALS_H