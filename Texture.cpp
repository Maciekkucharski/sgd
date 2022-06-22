#include "Texture.h"
SDL_Texture* Texture::Texture(const char* filelocation, SDL_Renderer* ren){
    SDL_Surface surface;
    surface = IMG_Load(filelocation);
    SDL_Texture* tex;
    tex = SDL_CreateTex;
};
