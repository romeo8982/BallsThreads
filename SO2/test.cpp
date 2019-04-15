#include "Draw.h"
#include <thread>
#include <iostream>
#include <vector>
#include <atomic>
#include <algorithm>


bool running = true;
std::vector <std::thread> threads;
std::vector <Ball> balls;

void Close ()
{
	while(running)
	{
		char q = getchar();
        if(q == 'q')
            running = false;
	}
}

void do_join(std::thread& t)
{
    t.join();
}

void join_all(std::vector<std::thread>& v)
{
    std::for_each(v.begin(),v.end(),do_join);
}

void UpdateBall(Ball &ball, int update_time)
{
	const auto wait_duration = std::chrono::milliseconds(update_time);
	while(running)
    {
		ball.Update();
		std::this_thread::sleep_for(wait_duration); 
    }
}

void Refresh(Draw &draw, int update_time)
{
	const auto wait_duration = std::chrono::milliseconds(update_time);
	while(running)
    {
		draw.Move(balls);
		std::this_thread::sleep_for(wait_duration); 
    }
}

void NewBall(int update_time)
{
	const auto wait_duration = std::chrono::milliseconds(update_time);
		while(running)
		{
		double volacity = rand() % 100 + 1;
		int x_position = rand()%15+1;
		int y_position = rand()%50+1;
		bool goDown = rand()%2;
		bool goRight = rand()%2;
		Ball ball(volacity,x_position,y_position,goDown,goRight);
		balls.push_back(ball);
		std::thread thread(std::thread(UpdateBall,std::ref(balls[balls.size()-1]),ball.getVolacity()));
		threads.push_back(std::move(thread));
		std::this_thread::sleep_for(wait_duration);
		}
}

int main()
{
	srand (time(NULL));
	
	const unsigned int update_interval0 = 5000;
	const unsigned int update_interval2 = 10;

	Draw draw;
	
	std::thread th0 (NewBall,update_interval0);
	std::thread th2 (Refresh,std::ref(draw),update_interval2);
	std::thread exit (Close);

    th0.join();
	th2.join();
	join_all(threads);
	exit.join();

	return 0;
}