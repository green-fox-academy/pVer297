//
// Created by Egri Zoltán on 2019. 01. 29..
//

#include "station.h"

Station::Station(int initGas)
{
    gasAmount = initGas;
}

void Station::fill(Car &carToFill)
{
    while (!carToFill.isFull() && gasAmount > 0) {
        std::cout << "Filling car!" << std::endl;
        carToFill.fill();
        gasAmount--;
    }
    std::cout << "Remaining gas in the station: " << gasAmount << "L" << std::endl;
}