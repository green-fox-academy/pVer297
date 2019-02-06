//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef INSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTS_INSTRUMENT_H

#include <iostream>

class Instrument
{
 protected:
    std::string _name;

 public:
    virtual void play() = 0;

};

#endif //INSTRUMENTS_INSTRUMENT_H
