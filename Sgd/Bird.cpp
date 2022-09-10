#include"Bird.h"
#include<iostream>
#include<SDL.h>

void Bird::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}


void Bird::accUpward() {
	v_y = 500;
}

void Bird::accForward() {
	a_x = 150;
}

void Bird::stopAccForward() {
	a_x = -300;
}

void Bird::accBackward() {
	a_x = -150;
}

void Bird::stopAccBackward() {
	a_x = 300;
}

void Bird::Frame() {
	v_x += a_x * tickDuration;
	if ((v_x >= 0 && (v_x + a_x * tickDuration) <= 0)||(v_x <= 0 && (v_x + a_x * tickDuration) >= 0)) {
		a_x = 0;
		v_x = 0;
	}
	s_x += v_x * tickDuration;
	v_y += (a_y + gravity) * tickDuration;
	s_y += v_y * tickDuration;

	setDest(s_x+40, -s_y+10, 42, 60);
}

double Bird::getxVelocity() {
	return v_x;
}
void Bird::setxVelocity(double value) {
	v_x = value;
}
double Bird::getxAcc() {
	return a_x;
}
void Bird::setxAcc(double value) {
	a_x = value;
}
double Bird::getDt() {
	return dt;
}
void Bird::setDt() {
	dt = SDL_GetTicks();
}
void Bird::Update() {
	setDt();
}
