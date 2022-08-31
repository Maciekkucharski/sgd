#pragma once
#include "Object.h"
class Bird :public Object {
public:
	void Render(SDL_Renderer* ren);
	void Jump();
	void accLeft();
	void accRight();
	bool getJumping();
	bool getAcceleratingRight();
	bool getAcceleratingLeft();
	void setAcceleratingRight(bool value);
	void setAcceleratingLeft(bool value);
	void Gravity();
	double getPdt();
	void setPdt();
	double getDt();
	void setDt();
	double getFdt();
	void setFdt();
	double getPdt_x();
	void setPdt_x();
	double getDt_x();
	void setDt_x();
	double getFdt_x();
	void setFdt_x();
	void Update();
	void horizontalGravity();

private:
	double pdt, dt, fdt = 0;
	double gravity = 9;
	double xAcc = 0;
	double xVelocity = 0;
	double jumpTimer;
	double last_jump = 0;
	double last_acc = 0;
	bool jumping = false;
	bool acceleratingRight = false;
	bool acceleratingLeft = false;
	double pdt_x, dt_x, fdt_x = 0;
};