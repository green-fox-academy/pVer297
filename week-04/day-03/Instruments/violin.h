//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H

#include "stringedInstrument.h"

class Violin : public StringedInstrument
{
 public:
    Violin();
    Violin(int numberOfStrings);
    std::string sound() override;

};

#endif //INSTRUMENTS_VIOLIN_H
