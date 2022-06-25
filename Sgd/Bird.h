#pragma once
#include "Object.h"
class Bird :public Object {
public:
	void Render(SDL_Renderer* ren);
	void getJumpTime();
	void Jump();
	void accLeft();
	void accRight();
	bool getJumping();
	void Gravity();
	double getPdt();
	void setPdt();
	double getDt();
	void setDt();
	double getFdt();
	void setFdt();
	void Update();
	void moveHorizontally();


private:
	double pdt, dt, fdt = 0;
	double gravity = 9;
	double xVelocity = 10;
	double jumpTimer;
	double last_jump = 0;
	bool jumping = false;
};