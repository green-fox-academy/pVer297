//
// Created by Egri Zoltán on 2019. 01. 30..
//

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include <iostream>
#include "PirateNames.h"

class Pirate
{
 private:
    int drinkLevel = 0;
    bool isDead = false;
    bool isPassedOut = false;
    bool hasParrot;
    std::string name;
    std::string generatePirateName();

 public:
    Pirate();
    Pirate(std::string name_);
    void drinkSomeRum();
    void howItsGoingMate();
    void brawl(Pirate& anotherPirate);
    void die();
    void passOut();
    bool isAwake();
    bool isAlive();
    std::string checkParrot();
    std::string getName();
    std::string getState();
    int getDrinkLevel();
};

#endif //PIRATES_PIRATE_H
