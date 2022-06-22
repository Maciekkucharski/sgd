#include "TextureMenager.h"

SDL_Texture* TextureMenager::Texture(const char* file, SDL_Renderer* ren) {
    SDL_Surface* surface;
    surface = IMG_Load(file);
    SDL_Texture* tex;
    tex = SDL_CreateTextureFromSurface(ren, surface);
    return tex;
}
