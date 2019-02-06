//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H

#include "stringedInstrument.h"

class ElectricGuitar : public StringedInstrument
{
 public:
    ElectricGuitar();
    ElectricGuitar(int numberOfStrings);
    std::string sound() override;

};

#endif //INSTRUMENTS_ELECTRICGUITAR_H
