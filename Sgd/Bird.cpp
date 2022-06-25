#include"Bird.h"
#include<iostream>
#include<SDL.h>

void Bird::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}



void Bird::Gravity() {
	if (getJumping()) {
		accelerator1 += 0.020;
		accelerator2 += 0.020;
		jumpHeight = jumpHeight + gravity;
		y = y +gravity +accelerator1 +accelerator2+ jumpHeight;
		setDest(25, y, 28, 38);
		if (jumpHeight>0) {
			jumping = false;
			jumpHeight = -6;
		}
	}
	else {
		accelerator1 += 0.01;
		accelerator2 += 0.01;
		y = y + gravity + accelerator1 + accelerator2;
		setDest(25, y, 28, 38);
	}
}

void Bird::Jump() {
	if (jumpTimer - last_jump > 50) {
		accelerator1 = 0;
		accelerator2 = 0;
		jumping = true;
		last_jump = jumpTimer;
	}
	else {
		Gravity();
	}
}


void Bird::getJumpTime() {
	jumpTimer = SDL_GetTicks();

}

bool Bird::getJumping() {
	return jumping;
}