#include <iostream>
#include <SDL.h>
#include <cmath>
#include "branch.h"
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

const char WINDOW_DISPLAY_NAME[] = "Fractal Tree";

//Draws geometry on the canvas
void draw();

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void generateBranch(int startX, int startY, int length, double angleOfBranches, double angle = 0)
{
    if (length < 5) return;
    Branch branch(gRenderer, startX, startY, length, angle);
    branch.showBranch();

    generateBranch(branch.getEndPoint().x,
                   branch.getEndPoint().y,
                   length - 10,
                   angleOfBranches,
                   angle - angleOfBranches);//left
    generateBranch(branch.getEndPoint().x,
                   branch.getEndPoint().y,
                   length - 8,
                   angleOfBranches,
                   angle);//middle
    generateBranch(branch.getEndPoint().x,
                   branch.getEndPoint().y,
                   length - 10,
                   angleOfBranches,
                   angle + angleOfBranches);//right
}

std::vector<Branch> branches;

void draw()
{
    //iterative, with animation
    for (int i = 0; i < branches.size(); i++) {
        if (!branches.at(i).isDone()) {
                branches.push_back(Branch(gRenderer,
                                          branches.at(i).getEndPoint().x,
                                          branches.at(i).getEndPoint().y,
                                          branches.at(i).nextLength(),
                                          branches.at(i).lastAngle()));
                branches.push_back(Branch(gRenderer,
                                          branches.at(i).getEndPoint().x,
                                          branches.at(i).getEndPoint().y,
                                          branches.at(i).nextLength(),
                                          branches.at(i).lastAngle() + 22));
                branches.push_back(Branch(gRenderer,
                                          branches.at(i).getEndPoint().x,
                                          branches.at(i).getEndPoint().y,
                                          branches.at(i).nextLength(),
                                          branches.at(i).lastAngle() - 22));
            break;
        }
        branches.at(i).showBranch();
    }

    //generateBranch(SCREEN_WIDTH / 2, SCREEN_HEIGHT, 100, 22.5); //recursive, without animation
}

bool init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow(WINDOW_DISPLAY_NAME,
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH,
                               SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main(int argc, char* args[])
{
    //Start up SDL and create window
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    branches.push_back(Branch(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT, 100));

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0, 50, 60, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}