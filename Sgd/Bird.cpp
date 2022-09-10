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
	float t = 0.0069;

	v_x += a_x * t;
	if ((v_x >= 0 && (v_x + a_x * t) <= 0)||(v_x <= 0 && (v_x + a_x * t) >= 0)) {
	
		a_x = 0;
		v_x = 0;
	}
	s_x += v_x * t;

	v_y += (a_y + gravity) * t;
	s_y += v_y * t;

	setDest(s_x+40, -s_y+10, 42, 60);

}

void Bird::changeAccForwards(int accelerate) {
	setAcceleratingRight(accelerate > 0);
	if ((a_x == 0 && acceleratingRight)) {
		setPdt_x();
		setMovingRight(true);
	}
	if ((a_x == 0 && acceleratingRight) || (a_x == 5 && !acceleratingRight)) {
		setPdt_x();
		setDrag(accelerate < 0);
		xEventStartVelocity = v_x;
		
		setxAcc(5 * accelerate);
	}

}








bool Bird::getJumping() {
	return jumping;
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
bool Bird::getAcceleratingRight() {
	return acceleratingRight;
}
void Bird::setAcceleratingRight(bool value) {
	acceleratingRight = value;
}
bool Bird::getAcceleratingLeft() {
	return acceleratingLeft;
}
void Bird::setAcceleratingLeft(bool value) {
	acceleratingLeft = value;
}
bool Bird::getMovingright() {
	return movingRight;
}
void Bird::setMovingRight(bool value) {
	movingRight = value;
}
bool Bird::getMovingLeft() {
	return movingLeft;
}
void Bird::setMovingLeft(bool value) {
	movingLeft = value;
}
bool Bird::getDrag() {
	return drag;
}
void Bird::setDrag(bool value) {
	drag = value;
}

double Bird::getPdt() {
	return pdt;
}
void Bird::setPdt() {
	pdt = dt;
}
double Bird::getDt() {
	return dt;
}
void Bird::setDt() {
	dt = SDL_GetTicks();
}
double Bird::getFdt() {
	return fdt;
}
void Bird::setFdt() {
	fdt = (getDt() - getPdt())/1000;
}
double Bird::getPdt_x() {
	return pdt_x;
}
void Bird::setPdt_x() {
	pdt_x = dt;
}
double Bird::getFdt_x() {
	return fdt_x;
}
void Bird::setFdt_x() {
		fdt_x = (getDt() - getPdt_x()) / 1000;
}
	

void Bird::Update() {
	setDt();
}
