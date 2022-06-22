#pragma once
#ifndef SGD_TEXTURE_H
#define SGD_TEXTURE_H

#include "GameLoop.h"
class Texture {
public:
    static SDL_Texture* Texture(const char* filelocation, SDL_Renderer * ren);
};


#endif //SGD_TEXTURE_H
