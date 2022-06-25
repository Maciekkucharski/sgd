#include <SDL.h>
#include <iostream>
#include <Windows.h>
#include "Gameloop.h"

GameLoop* g = new GameLoop();  //pointer to gameloop class to access function

int main(int argc, char* argv[]) {

    double first;
    double last = 0;
    g->Initialize();
    while (g->getState()) {
        g->Renderer();
        g->Event();
        g->Update();
        g->CollisionDetection();
        first = SDL_GetTicks();
        if (first - last < 6.9) {
            SDL_Delay(6.9 - (first - last));
        }
        
        last = first;
    }
    g->Renderer();
    Sleep(3000);
    g->Clear();

    return 0;
}

