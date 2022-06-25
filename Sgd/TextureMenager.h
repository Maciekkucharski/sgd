#pragma once
#include<SDL.h>
#include<SDL_image.h>

class TextureMenager {
public:
    static SDL_Texture* Texture(const char* file, SDL_Renderer* renderer);
};



