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

std::vector<Branch> branches;
std::vector<Branch> branches2;
std::vector<Branch> branches3;

int angle = 120;

void iterateTree(std::vector<Branch>& tree)
{
    for (int i = 0; i < tree.size(); i++) {
        if (!tree.at(i).isDone()) {
            tree.push_back(Branch(gRenderer,
                                  tree.at(i).getEndPoint().x,
                                  tree.at(i).getEndPoint().y,
                                  tree.at(i).nextLength(),
                                  tree.at(i).lastAngle()));
            tree.push_back(Branch(gRenderer,
                                  tree.at(i).getEndPoint().x,
                                  tree.at(i).getEndPoint().y,
                                  tree.at(i).nextLength(),
                                  tree.at(i).lastAngle() + angle));
            tree.push_back(Branch(gRenderer,
                                  tree.at(i).getEndPoint().x,
                                  tree.at(i).getEndPoint().y,
                                  tree.at(i).nextLength(),
                                  tree.at(i).lastAngle() - angle));
            break;
        }
        tree.at(i).showBranch();
    }
}

void draw()
{
    iterateTree(branches);
    iterateTree(branches2);
    iterateTree(branches3);
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

    branches.push_back(Branch(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150));
    branches2.push_back(Branch(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150, 120));
    branches3.push_back(Branch(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150, -120));

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
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}