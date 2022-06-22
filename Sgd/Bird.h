#pragma once
#include "object.h"
class Bird :public Object {
public:
private:
	void Render(SDL_Renderer* ren, SDL_Texture* Tex, SDL_Rect src, SDL_Rect dest);
};