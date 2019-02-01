//
// Created by Egri Zoltán on 2019. 02. 01..
//

#include "branch.h"

Branch::Branch(SDL_Renderer* gRenderer, int startX, int startY, int length, double angle)
{
    _startX = startX;
    _startY = startY;
    _renderer = gRenderer;
    _length = length;
    _angleInDegrees = angle;

    _angleInRadians += degreesToRadians(angle);

    _endX = startX + (int) round(length * cos(_angleInRadians));
    _endY = startY + (int) round(-length * sin(_angleInRadians));
}

void Branch::showBranch()
{
    SDL_SetRenderDrawColor(_renderer, 255, 230, _length, 255);
    SDL_RenderDrawLine(_renderer, _startX, _startY, _endX, _endY);
}

int Branch::nextLength()
{
    return _length * 0.8;
}

double Branch::lastAngle()
{
    return _angleInDegrees;
}

SDL_Point Branch::getEndPoint()
{
    numOfBranches++;
    return SDL_Point{_endX, _endY};
}

bool Branch::isDone()
{
    return (_length < 5) || (numOfBranches >= maxBranches);
}
