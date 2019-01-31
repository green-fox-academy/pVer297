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
    std::vector<Pirate> crew;
    Pirate captain;

};

#endif //PIRATES_SHIP_H
