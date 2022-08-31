#include"Bird.h"
#include<iostream>
#include<SDL.h>

void Bird::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}



void Bird::Gravity() {
	double x;
	double tmp_fdt = (getDt() - getPdt())/1000;	
	if (getDest().x > 40) {
		x = getDest().x;
	}
	else {
		x = 40;
	}
	if (getJumping()){
		double tmp_dest = getDest().y;
		double y = getDest().y - 22 * tmp_fdt + 4.5 * tmp_fdt * tmp_fdt * gravity;
		setDest(x, y, 42, 60);
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
		setDest(x, y, 42, 60);
	}


	tmp_fdt = (getDt() - getPdt_x()) / 1000;
	if (getAcceleratingRight()) {
		double tmp_dest = getDest().x;
		std::cout << getPdt_x() << std::endl;
		double x = getDest().x + xAcc * tmp_fdt;
		setDest(x, getDest().y, 42, 60);

		
	}





}

/*void Bird::moveHorizontally() {

}
}*/
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
	setFdt_x();
	setPdt_x();
	acceleratingRight = true;
	last_acc = dt_x;
	Gravity();

}


void Bird::Update() {
	setDt();
	setDt_x();
}




bool Bird::getJumping() {
	return jumping;
}

bool Bird::getAcceleratingLeft() {
	return acceleratingLeft;
}
void Bird::setAcceleratingLeft(bool value) {
	acceleratingLeft = value;
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
	fdt = getDt() - getPdt();
}

double Bird::getPdt_x() {
	return pdt_x;
}

void Bird::setPdt_x() {
	pdt_x = dt_x;
}
double Bird::getDt_x() {
	return dt_x;
}
void Bird::setDt_x() {
	dt_x = SDL_GetTicks();
}
double Bird::getFdt_x() {
	return fdt_x;
}
void Bird::setFdt_x() {
	fdt_x = getDt_x() - getPdt_x();
}