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
	double y;
	std::cout << "\nEventStartVelocity->" << xEventStartVelocity <<  "	vel->" << xVelocity<< "		fdtx->" << getFdt_x() << "		pdtx->" << getPdt_x() << "	xacc->" << xAcc << "	drag->" << drag;
	setFdt();
	if (getJumping()){
		double tmp_dest = getDest().y;
		y = getDest().y - jumpSpeed * getFdt() + (getFdt() * getFdt() * gravity) ;
		
		setDest(getDest().x, y, 42, 60);
		if (tmp_dest < y) {
			setPdt();
			jumping = false;
		}
	}
	else
	{
		y = getDest().y + gravity * (getFdt() * getFdt());
		
	}
	setDest(getDest().x, 40, 42, 60);//change 40 to y

	setFdt_x();
	//if (getAcceleratingRight()) {
	x = getDest().x + xEventStartVelocity * getFdt_x() + xAcc * getFdt_x() * getFdt_x();
	xVelocity = xEventStartVelocity + xAcc * getFdt_x();
//	}
	
	
	if (abs(xVelocity)< 0.05 && getDrag()) {
		setxAcc(0);
		setxVelocity(0);
		xEventStartVelocity = 0;
		setDrag(false);
		setAcceleratingRight(false);
		setPdt_x();
	}
	
	setDest(x, getDest().y, 42, 60);
}



	


void Bird::changeAccForwards(int accelerate) {
	setAcceleratingRight(accelerate > 0);
	if ((xAcc == 0 && acceleratingRight)) {
		setPdt_x();
		setMovingRight(true);
	}
	if ((xAcc == 0 && acceleratingRight) || (xAcc == 5 && !acceleratingRight)) {
		setPdt_x();
		setDrag(accelerate < 0);
		xEventStartVelocity = xVelocity;
		
		setxAcc(5 * accelerate);
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
