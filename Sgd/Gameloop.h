 #pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include "Object.h"
#include "Bird.h"
#include "Background.h"

class GameLoop {
private:
    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    bool state;
    SDL_Texture* background;
    Bird b;
    Background bg;
public:
    GameLoop();

    void Initialize();

    void Update();

    void Event();

    void Renderer();

    void Clear();

    bool getState();
};