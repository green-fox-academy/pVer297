//
// Created by Egri Zoltán on 2019. 01. 29..
//

#ifndef SHARPIE_SET_SHARPIE_SET_H
#define SHARPIE_SET_SHARPIE_SET_H

#include <iostream>
#include <vector>
#include "sharpie.h"

class SharpieSet
{
 private:
    std::vector<Sharpie> *sharpies;

 public:
    SharpieSet(std::vector<Sharpie> *sharpies_);
    int countUsable();
    std::string removeTrash();
};

#endif //SHARPIE_SET_SHARPIE_SET_H
