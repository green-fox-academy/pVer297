//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef DEVICES_COPIER_H
#define DEVICES_COPIER_H

#include "printer2D.h"
#include "scanner.h"

class Copier : public Printer2D, public Scanner
{
 public:
    Copier(int sizeX, int sizeY, int speed);
    void copy();
};

#endif //DEVICES_COPIER_H
