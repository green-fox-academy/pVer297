//
// Created by Egri Zoltán on 2019. 02. 01..
//

#ifndef FRACTAL_TREE_BRANCH_H
#define FRACTAL_TREE_BRANCH_H

#include <iostream>
#include <SDL.h>
#include <math.h>

#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

class Branch
{
 private:
    int _startX;
    int _startY;
    int _endX;
    int _endY;
    int _length;
    double _angleInRadians = degreesToRadians(90);
    double _angleInDegrees;
    SDL_Renderer* _renderer;
    const int maxBranches = 6; //3 but for each branch its incremented by 2(getEnd x and y)
    int numOfBranches = 0;

 public:
    Branch(SDL_Renderer* gRenderer, int startX, int startY, int length, double angle = 0);
    void showBranch();
    bool isDone();
    int nextLength();
    double lastAngle();
    SDL_Point getEndPoint();
};

#endif //FRACTAL_TREE_BRANCH_H
