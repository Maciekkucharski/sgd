#include <SDL.h>
#include <iostream>
#include "Gameloop.h"

GameLoop* g = new GameLoop();  //pointer to gameloop class to access function

int main(int argc, char* argv[]) {

    double first;
    double last = 0;
    g->Initialize();
    while (g->getState()) {
        g->Renderer();
        g->Event();
        first = SDL_GetTicks();
        if (first - last < 6.9) {
            SDL_Delay(6.9 - (first - last));
        }
        
        last = first;
    }
    g->Clear();

    return 0;
}

