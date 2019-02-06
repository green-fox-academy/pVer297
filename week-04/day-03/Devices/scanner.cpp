//
// Created by Egri Zoltán on 2019. 02. 06..
//

#include "scanner.h"
Scanner::Scanner(int speed)
{
    _speed = speed;
}
void Scanner::scan()
{
    std::cout << "I'm scanning a document with " << _speed << " ppm." << std::endl;
}
