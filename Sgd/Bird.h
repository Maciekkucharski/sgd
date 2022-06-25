#pragma once
#include "Object.h"
class Bird :public Object {
public:
	void Render(SDL_Renderer* ren);
	void getJumpTime();
	void Jump();
	bool getJumping();
	void Gravity();
private:
	double gravity = 0.1;
	double jumpHeight = -6;
	double jumpTimer;
	double last_jump = 0;
	double y = 256;
	double accelerator1 = 0;
	double accelerator2 = 0;
	int animationtimer;
	bool jumping = false;
	SDL_Texture* Tex1;
	SDL_Texture* Tex2;



};