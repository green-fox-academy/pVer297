//
// Created by Egri Zoltán on 2019. 02. 01..
//

#include "rect.h"

Rect::Rect(SDL_Renderer* renderer, int xPos, int yPos, int size, int color)
{
    _color = color;
    _xPos = xPos;
    _yPos = yPos;
    _size = size;
    _renderer = renderer;
}

std::vector<Rect> Rect::generate()
{
    std::vector<Rect> rects;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            int newSize = _size / 3;
            if (x * y != 1) {
                Rect rect(_renderer, _xPos + (x * newSize), _yPos + (y * newSize), newSize, 255);
                rects.push_back(rect);
            }
        }
    }
    return rects;
}

void Rect::show()
{
    SDL_SetRenderDrawColor(_renderer, _color, _color, _color, 255);
    SDL_Rect rectToShow = {_xPos, _yPos, _size, _size};
    SDL_RenderFillRect(_renderer, &rectToShow);
}