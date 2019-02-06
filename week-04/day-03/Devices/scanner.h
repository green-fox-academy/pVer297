//
// Created by Egri Zoltán on 2019. 02. 06..
//

#ifndef DEVICES_SCANNER_H
#define DEVICES_SCANNER_H

#include <iostream>

class Scanner
{
 protected:
    int _speed;

 public:
    Scanner(int speed);
    void scan();

};

#endif //DEVICES_SCANNER_H
