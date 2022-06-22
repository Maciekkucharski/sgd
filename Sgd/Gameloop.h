#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>

class GameLoop {
private:
    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;
    SDL_Window* window;
    SDL_Renderer* renderer;
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