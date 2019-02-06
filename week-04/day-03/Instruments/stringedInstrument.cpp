//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "stringedInstrument.h"
void StringedInstrument::play()
{
    std::cout << _name << ", a " << _numberOfStrings
              << "-stringed instrument that goes " << sound() << std::endl;
}
