#pragma once
#include "Object.h"
class Bird :public Object {
public:
	void Render(SDL_Renderer* ren);
	void Frame();
	void accForward();
	void accUpward();
	void stopAccForward();
	void accBackward();
	void stopAccBackward();
	double getDt();
	void setDt();
	void setxVelocity(double value);
	double getxVelocity();
	void setxAcc(double value);
	double getxAcc();
	void Update();

private:
	double dt = 0;
	double gravity = -500;
	double a_x = 0;
	double v_x = 0;
	double s_x = 0;
	double a_y = 0;
	double s_y = 0;
	double v_y = 0;
	double tickDuration = 0.0069;
};