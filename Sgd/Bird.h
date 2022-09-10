#pragma once
#include "Object.h"
class Bird :public Object {
public:
	void Render(SDL_Renderer* ren);
	void Jump();
	void changeAccForwards(int accelerate);
	bool getJumping();
	void Move();
	void Frame();
	void accForward();
	void accUpward();
	void stopAccForward();
	void stopAccUpward();
	void accBackward();
	void stopAccBackward();
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
	void setAcceleratingLeft(bool value);
	bool getAcceleratingLeft();
	void setMovingLeft(bool value);
	bool getMovingLeft();
	void setMovingRight(bool value);
	bool getMovingright();
	void setDrag(bool value);
	bool getDrag();
	void setFdt_x();
	void Update();

private:
	double pdt, dt, fdt = 0;
	double gravity = -500;
	double a_x = 0;
	double jumpSpeed = 20;
	double v_x = 0;
	double xEventStartVelocity = 0;
	double jumpTimer;
	bool jumping = false;
	bool acceleratingRight = false;
	bool acceleratingLeft = false;
	bool movingRight = false;
	bool movingLeft = false;
	double pdt_x, fdt_x = 0;
	bool drag = false;
	double s_x = 0;
	double a_y = 0;
	double s_y = 0;
	double v_y = 0;

};