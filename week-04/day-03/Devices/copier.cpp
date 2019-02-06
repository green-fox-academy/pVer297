//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "copier.h"
Copier::Copier(int sizeX, int sizeY, int speed) :
    Printer2D(sizeX, sizeY), Scanner(speed)
{

}
void Copier::copy()
{
    scan();
    std::cout << "and" << std::endl;
    print();
}
