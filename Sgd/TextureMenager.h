#pragma once
#include "GameLoop.h"


class TextureMenager {
public:
    static SDL_Texture* Texture(const char* file, SDL_Renderer* renderer);
};



