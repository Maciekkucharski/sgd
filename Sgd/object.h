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
	SDL_Rect& getSrc();
	void setSrc(int x, int y, int h, int w);
	SDL_Rect& getDest();
	void setDest(int x, int y, int h, int w);
	void CreateTexture(const char* address, SDL_Renderer* ren);
	void virtual Render(SDL_Renderer* ren) = 0;
	

};