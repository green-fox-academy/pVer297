//
// Created by Egri Zoltán on 2019. 01. 29..
//

#include "sharpie.h"

Sharpie::Sharpie(std::string color_, float width_)
{
    color = color_;
    width = width_;
    inkAmmount = 100;
}

void Sharpie::use()
{
    if (inkAmmount > 0) {
        std::cout << "Writing with " << color << " sharpie" << std::endl;
        inkAmmount -= width;
    } else {
        std::cout << "The " << color << " sharpie is empty" << std::endl;
    }
}

std::string Sharpie::getColor()
{
    return color;
}

float Sharpie::getWidth()
{
    return width;
}

float Sharpie::getInkAmmount()
{
    return inkAmmount;
}

bool Sharpie::isEmpty()
{
    return inkAmmount <= 0;
}