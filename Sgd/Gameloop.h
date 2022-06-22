#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include "TextureMenager.h"

class GameLoop {
private:
    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    bool state;
    SDL_Texture* bird;
    SDL_Rect srcBird, destBird;
public:
    GameLoop();

    void Initialize();

    void Update();

    void Event();

    void Renderer();

    void Clear();

    bool getState();
};