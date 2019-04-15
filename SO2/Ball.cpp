#include "Ball.h"

Ball::Ball(double volacity, int y_position, int x_position, bool goDown, bool goRight)
{
    this->volacity=volacity;
    this->y_position=y_position;
    this->x_position=x_position;
    this->goDown = goDown;
    this->goRight = goRight;
}
void Ball::Update()
{
    if(x_position<=50&&!goDown)
	{
		x_position--;
		if(x_position<=1) 
		{ 
		  goDown=true;
	      x_position--;
		}
	}
	if(x_position<50&&goDown)
	{
		x_position++;
		if(x_position>=50) goDown=false;
	}
	if(y_position<=15&&!goRight)
	{
		y_position--;
		if(y_position<=1) 
		{ 
			goRight=true;
			y_position--;
		}
	}
	if(y_position<15&&goRight)
	{
		y_position++;
		if(y_position>=15) goRight=false;
	}
}

double Ball::getVolacity(){return volacity;}
int Ball::getXPosition(){return y_position;}
int Ball::getYPosition(){return x_position;}
bool Ball::getGoDown(){return goDown;}
bool Ball::getGoRight(){return goRight;}

void Ball::setVolacity(double volacity){this->volacity=volacity;}
void Ball::setXPosition(int y_position){this->y_position=y_position;}
void Ball::setYPosition(int x_position){this->x_position=x_position;}
void Ball::setGoDown(bool goDown){this->goDown=goDown;}
void Ball::setGoRight(bool goRight){this->goRight=goRight;}