#include"Bird.h"
#include<iostream>
#include<SDL.h>

void Bird::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}



void Bird::Gravity() {
	double tmp_fdt = (getDt() - getPdt())/1000;	
	if (getJumping()){
		double tmp_dest = getDest().y;
		double velocity = gravity * tmp_fdt + 20;
		double y = getDest().y - 22 * tmp_fdt + 4.5 * tmp_fdt * tmp_fdt * gravity;
		setDest(40, y, 42, 60);
		if (tmp_dest < y) {
			setFdt();
			setPdt();
			jumping = false;
		}
	}
	else
	{
		double velocity = gravity * tmp_fdt;
		int y = getDest().y + gravity * tmp_fdt * tmp_fdt + velocity;
		setDest(40, y, 42, 60);
	}
}

void Bird::moveHorizontally() {

}

void Bird::Jump() {
	if (dt - last_jump > 50) {
		setFdt();
		setPdt();
		jumping = true;
		last_jump = dt;
	}
	else {
		Gravity();
	}
}

void Bird::accLeft() {
	xVelocity--;
}

void Bird::accRight() {
	xVelocity++;
}


void Bird::Update() {
	setDt();
}




bool Bird::getJumping() {
	return jumping;
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
	fdt = getDt() - getPdt();
}

