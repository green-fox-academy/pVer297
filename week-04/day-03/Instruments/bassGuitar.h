//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H

#include "stringedInstrument.h"

class BassGuitar : public StringedInstrument
{
 public:
    BassGuitar();
    BassGuitar(int numberOfStrings);
    std::string sound() override;

};

#endif //INSTRUMENTS_BASSGUITAR_H
