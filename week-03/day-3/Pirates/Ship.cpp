//
// Created by Egri Zoltán on 2019. 01. 30..
//

#include "Ship.h"

Ship::Ship(std::string shipName, std::string captainName)
{
    _shipName = shipName;
    _captainName = captainName;
}

void Ship::fillShip()
{
    _captain = Pirate(_captainName);

    for (int i = 0; i < rand() % 70; i++) {
        _crew.push_back(Pirate());
    }
}

void Ship::info()
{
    std::cout << _captainName << " has consumed " << _captain.getDrinkLevel() << " rum. ";
    std::cout << _captain.getState() << std::endl;
    std::cout << "There is " << countAlive() << " handy pirates on the ship" << std::endl;
}
bool Ship::battle(Ship& otherShip)
{
    if (calculateScore() == otherShip.calculateScore()) {
        std::cout << "Draw, they both have lost some good men" << std::endl;
        lostBattle();
        otherShip.lostBattle();
        return false;
    } else if (calculateScore() > otherShip.calculateScore()) {
        std::cout << "The " << getShipName() << " wins" << std::endl;
        wonBattle();
        otherShip.lostBattle();
        return true;
    } else {
        std::cout << "The " << otherShip.getShipName() << " wins" << std::endl;
        lostBattle();
        otherShip.wonBattle();
        return false;
    }
}

void Ship::lostBattle()
{
    int pirateLost = rand() % countAlive();
    for (int i = 0; i < pirateLost; i++) {
        int indexToKill = rand() % _crew.size();
        if (_crew[indexToKill].isAlive()) {
            _crew[indexToKill].die();
        } else {
            i--;
        }
    }
}

void Ship::wonBattle()
{
    _captain.drinkSomeRum();
    for (Pirate pirates : _crew) {
        pirates.drinkSomeRum();
    }
}

int Ship::countAlive()
{
    int count = 0;
    for (Pirate pirate : _crew) {
        if (pirate.isAlive()) {
            count++;
        }
    }
    return count;
}
int Ship::calculateScore()
{
    return countAlive() - _captain.getDrinkLevel();
}

std::string Ship::getShipName()
{
    return _shipName;
}