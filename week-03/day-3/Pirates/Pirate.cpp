//
// Created by Egri Zoltán on 2019. 01. 30..
//

#include "Pirate.h"

Pirate::Pirate()
{
    name = generatePirateName();
    hasParrot = rand() % 2;
}

Pirate::Pirate(std::string name_)
{
    name = name_;
    hasParrot = rand() % 2;
}

void Pirate::drinkSomeRum()
{
    if (isAwake()) {
        drinkLevel++;
    }
}

void Pirate::howItsGoingMate()
{
    if (isAwake()) {
        if (drinkLevel <= 4) {
            std::cout << "Pour me anudder!" << std::endl;
        } else {
            std::cout << "Arghh, I'm " << name << " da Pirate. How d'ya d'ink its goin?" << std::endl;
            passOut();
        }
    }
}

void Pirate::die()
{
    isDead = true;
}

void Pirate::passOut()
{
    isPassedOut = true;
}

void Pirate::brawl(Pirate &anotherPirate)
{
    if (anotherPirate.isAwake() && isAwake()) {
        int outcome = rand() % 3;
        switch (outcome) {
            case 0://first pirate dies
                die();
                std::cout << anotherPirate.getName() << " won" << std::endl;
                std::cout << getName() << " dies" << std::endl;
                break;
            case 1://second pirate dies
                anotherPirate.die();
                std::cout << getName() << " won" << std::endl;
                std::cout << anotherPirate.getName() << " dies" << std::endl;
                break;
            case 2: //both pass out
                passOut();
                anotherPirate.passOut();
                std::cout << "Draw! They both got knocked out." << std::endl;
                break;
        }
    }
}

bool Pirate::isAwake()
{
    if (isDead) {
        std::cout << "He's dead!" << checkParrot() << std::endl;
        return false;
    } else if (isPassedOut) {
        std::cout << name << " is passed out" << checkParrot() << std::endl;
        return false;
    } else {
        return true;
    }
}

std::string Pirate::checkParrot()
{
    if (hasParrot) {
        return ", but his parrot looks interesting";
    }
    return "";
}

std::string Pirate::generatePirateName()
{
    int index = rand() % (sizeof(pirateNames) / sizeof(pirateNames[0]));
    return pirateNames[index];
}

std::string Pirate::getName()
{
    return name;
}