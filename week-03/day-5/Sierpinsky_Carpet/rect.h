//
// Created by Egri Zoltán on 2019. 02. 01..
//

#ifndef SIERPINSKY_CARPET_RECT_H
#define SIERPINSKY_CARPET_RECT_H

#include <iostream>
#include <vector>
#include "SDL.h"

class Rect
{
 private:
    int _xPos;
    int _yPos;
    int _size;
    int _color;
    SDL_Renderer* _renderer;

 public:
    Rect(SDL_Renderer* renderer, int xPos, int yPos, int size, int color);
    void show();

    std::vector<Rect> generate();

};

#endif //SIERPINSKY_CARPET_RECT_H
