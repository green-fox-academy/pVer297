//
// Created by Egri Zoltán on 2019. 01. 29..
//

#ifndef SHARPIE_SET_SHARPIE_H
#define SHARPIE_SET_SHARPIE_H

#include <iostream>

class Sharpie
{
 private:
    std::string color;
    float width;
    float inkAmmount;

 public:
    Sharpie(std::string color_, float width_);
    void use();
    std::string getColor();
    float getWidth();
    float getInkAmmount();
    bool isEmpty();
};
#endif //SHARPIE_SET_SHARPIE_H
