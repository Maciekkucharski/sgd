//
// Created by Maciek on 21.06.2022.
//

#ifndef SGD_GAMELOOP_H
#define SGD_GAMELOOP_H

#include<SDL.h>
#include<iostream>

class GameLoop {
private:
    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool state;
public:
     GameLoop();

    void Initialize();


    void Event();

    void Renderer();

    void Clear();

    bool getState();
};


#endif //SGD_GAMELOOP_H
