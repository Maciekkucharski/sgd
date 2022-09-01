#pragma once
#include "Object.h"
class Bird :public Object {
public:
	void Render(SDL_Renderer* ren);
	void Jump();
	void changeAccForwards(int accelerate);
	bool getJumping();
	void Move();
	double getPdt();
	void setPdt();
	double getDt();
	void setDt();
	double getFdt();
	void setFdt();
	double getPdt_x();
	void setPdt_x();
	double getFdt_x();
	void setxVelocity(double value);
	double getxVelocity();
	void setxAcc(double value);
	double getxAcc();
	void setAcceleratingRight(bool value);
	bool getAcceleratingRight();
	void setDrag(bool value);
	bool getDrag();
	void setFdt_x();
	void Update();

private:
	double pdt, dt, fdt = 0;
	double gravity = 40;
	double xAcc = 0;
	double jumpSpeed = 20;
	double xVelocity = 0;
	double xEventStartVelocity = 0;
	double jumpTimer;
	bool jumping = false;
	bool acceleratingRight = false;
	bool acceleratingLeft = false;
	double pdt_x, fdt_x = 0;
	bool drag = false;
};