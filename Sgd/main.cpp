#include <SDL.h>
#include <iostream>
#include "Gameloop.h"

GameLoop* g = new GameLoop();  //pointer to gameloop class to access function

int main(int argc, char* argv[]) {
    g->Initialize();
    while (g->getState()) {
        g->Renderer();
        g->Event();
    }
    g->Clear();

    return 0;
}

