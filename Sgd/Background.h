#pragma once
#include "Object.h"
class Background :public Object {
public:
	void PipeRender(SDL_Renderer* ren);
	void Update(SDL_Renderer* ren);
	void Render(SDL_Renderer* ren);
private:
}; 
