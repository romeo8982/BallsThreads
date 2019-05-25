#include "Draw.h"
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>


static bool running = true;
std::vector <std::thread> threads1;
std::vector <std::thread> threads2;
std::vector <Ball*> balls;
std::mutex mtx;
std::condition_variable cv;
static bool flag = false;

bool stuck=false;

void Close ()
{
	while(running)
	{
		char q = getchar();
        if(q == 'q')
		{
            running = false;
			Ball::setRunningFlag(false);
		}
	}
}

void do_join(std::thread& t)
{
    t.join();
}

void join_all()
{
    std::for_each(threads1.begin(),threads1.end(),do_join);
}

void Refresh(Draw &draw)
{
	while(running)
    {
		draw.Move(balls);
    }
}

void NewBall(int update_time)
{
	while(running)
	{
		double volacity = 185*((double)rand()/(double)RAND_MAX)+15;
		int x_position = rand()%15+1;
		int y_position = rand()%50+1;
		bool goDown = rand()%2;
		bool goRight = rand()%2;
		balls.push_back(new Ball(volacity,x_position,y_position,goDown,goRight));
		threads1.push_back(balls.back()->UpdateThread(/*std::ref(mtx),std::ref(cv),flag*/));
		//trzeba przekazać mutexa oraz cv ale nie wiem jeszcze jak jak to się uda to powinno dzialać
		//threads2.push_back(balls.back()->UnstuckThread());
		std::this_thread::sleep_for(std::chrono::milliseconds(update_time));
	}
}

int main()
{
	srand (time(NULL));
	
	const unsigned int update_interval0 = 3000;

	Ball::setRunningFlag(true);
	Draw draw;
	
	std::thread th0 (NewBall,update_interval0);
	std::thread th1 (Refresh,std::ref(draw));
	std::thread exit (Close);

    th0.join();
	th1.join();

	join_all();
	exit.join();

	return 0;
}