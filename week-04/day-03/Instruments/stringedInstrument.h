//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H

#include "instrument.h"

class StringedInstrument : public Instrument
{
 protected:
    int _numberOfStrings;
 public:
    virtual std::string sound() = 0;
    void play() override;
};

#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
