#include "Ball.h"
#include "Mutex.h"

bool Ball::running;

Ball::Ball(double volacity, int y_position, int x_position, bool goRight, bool goDown)
{
    this->volacity=volacity;
    this->y_position=y_position;
    this->x_position=x_position;
    this->goRight = goRight;
    this->goDown = goDown;
}

bool Ball::getRunningFlag()
{
    return running;
}

void Ball::setRunningFlag(bool flag)
{
    running = flag;
}

/*void Ball::Unstuck(std::mutex& mtx,std::condition_variable& cv, bool& flag)
{
	std::unique_lock<std::mutex> lck(mtx);
	flag = true;
	cv.notify_all();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	flag = false;
}*/

void Ball::Update(/*std::mutex mtx,std::condition_variable cv, bool flag*/)
{
	while(running)
    {
		if(x_position<=50&&!goRight)
		{
			x_position--;
			if(x_position<=1) 
			{
				SetMutex();
				goRight = true;
				x_position--;
			}
		}
		if(x_position<50&&goRight)
		{
			x_position++;
			if(x_position>=50) 
			{
				ObserveMutex();
				goRight=false;
			}
		}
		if(y_position<=15&&!goDown)
		{
			y_position--;
			if(y_position<=1) 
			{ 
				goDown=true;
				y_position--;
			}
		}
		if(y_position<15&&goDown)
		{
			y_position++;
			if(y_position>=15) goDown=false;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds((int)volacity));
	}
}

std::thread Ball::UpdateThread(/*std::mutex& mtx,std::condition_variable& cv, bool& flag*/)
{
	return std::thread(&Ball::Update,this);
}

/*std::thread Ball::UnstuckThread()
{
	return std::thread(&Ball::Unstuck,this);
}*/

double Ball::getVolacity(){return volacity;}
int Ball::getXPosition(){return y_position;}
int Ball::getYPosition(){return x_position;}
bool Ball::getGoRight(){return goRight;}
bool Ball::getGoDown(){return goDown;}

void Ball::setVolacity(double volacity){this->volacity=volacity;}
void Ball::setXPosition(int y_position){this->y_position=y_position;}
void Ball::setYPosition(int x_position){this->x_position=x_position;}
void Ball::setGoRight(bool goRight){this->goRight=goRight;}
void Ball::setGoDown(bool goDown){this->goDown=goDown;}