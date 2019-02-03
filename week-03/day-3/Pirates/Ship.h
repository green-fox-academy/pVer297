//
// Created by Egri Zoltán on 2019. 01. 30..
//

#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include <iostream>
#include <vector>
#include "Pirate.h"

class Ship
{
 private:
    std::vector<Pirate> _crew;
    Pirate _captain;

    std::string _captainName;
    std::string _shipName;

    void lostBattle();
    void wonBattle();

 public:
    Ship(std::string shipName, std::string captainName);
    void fillShip();
    void info();
    bool battle(Ship& otherShip);
    int countAlive();
    int calculateScore();
    std::string getShipName();
};

#endif //PIRATES_SHIP_H
