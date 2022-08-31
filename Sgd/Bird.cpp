#include"Bird.h"
#include<iostream>
#include<SDL.h>

void Bird::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Bird::Jump() {
	if (dt - getPdt() > 50) {
		setPdt();
		jumping = true;
	}
	else {
		Move();
	}
}

void Bird::Move() {
	
	double x;
	setFdt();
	
	if (getDest().x > 40) {
		x = getDest().x;
	}
	else {
		x = 40;
	}
	if (getJumping()){
		double tmp_dest = getDest().y;
		double y = getDest().y - jumpPower * getFdt() + 4.5 * getFdt() * getFdt() * gravity;
		setDest(x, y, 42, 60);
		if (tmp_dest < y) {
			setPdt();
			jumping = false;
		}
	}
	else
	{
		double velocity = gravity * getFdt();
		int y = getDest().y + gravity * getFdt() * getFdt() + velocity;
		setDest(x, y, 42, 60);
	}

	setFdt_x();
	if (getAcceleratingRight()) {
		x = getDest().x + xEventStartVelocity * getFdt_x() + xAcc * getFdt_x() * getFdt_x();
		xVelocity = (x - getDest().x) / getFdt_x() + xAcc * getFdt_x();

		setDest(x, getDest().y, 42, 60);
	}
	else {
		x = getDest().x + xEventStartVelocity * getFdt_x() - drag * getFdt_x() * getFdt_x();
		xVelocity = (x - getDest().x) / getFdt_x() - drag * getFdt_x();
	}
	
	
	if (xVelocity == 0 && !getAcceleratingRight() == 0) {
		//xAcc = 0;
	}
	
	setDest(x, getDest().y, 42, 60);
}



	


void Bird::changeAccForwards(bool accelerate) {
	if (xAcc == 0 && accelerate) {
		setAcceleratingRight(true);
		xEventStartVelocity = xVelocity;
		setPdt_x();
		xAcc = 5;
	}
	else if (xAcc == 5 && !accelerate) {
		setAcceleratingRight(false);
		setPdt_x();
		xAcc = 0;
		
	}

	

}








bool Bird::getJumping() {
	return jumping;
}

double Bird::getxVelocity() {
	return xVelocity;
}
void Bird::setxVelocity(double value) {
	xVelocity = value;
}
double Bird::getxAcc() {
	return xAcc;
}
void Bird::setxAcc(double value) {
	xAcc = value;
}
bool Bird::getAcceleratingRight() {
	return acceleratingRight;
}
void Bird::setAcceleratingRight(bool value) {
	acceleratingRight = value;
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
	if ((getDt() - getPdt_x()) / 1000 > 1) {
		fdt_x = 1;
	}
	else {
		fdt_x = (getDt() - getPdt_x()) / 1000;
	}
}
	

void Bird::Update() {
	setDt();
}
