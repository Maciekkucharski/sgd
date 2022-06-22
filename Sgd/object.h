#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include "TextureMenager.h"


class Object {
private:
	SDL_Rect src, dest;
	SDL_Texture* Tex;
public:
	Object();
	SDL_Texture* getTexture();
	void CreateTexture(const char* address, SDL_Renderer* ren, SDL_Texture* Tex);
	void virtual Render() = 0;
	

};