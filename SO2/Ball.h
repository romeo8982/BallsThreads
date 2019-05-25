#ifndef BALL_H
#define BALL_H
#include <thread>
#include <iostream>
#include <mutex> 
#include <condition_variable>

class Ball
{
    double volacity;
    bool goDown;
    bool goRight;
    int x_position;
    int y_position;
    static bool running;
    public:
    Ball(double volacity, int x_position, int y_position, bool goDown, bool goRight);
    void Update(/*std::mutex mtx,std::condition_variable cv, bool flag*/);
    //void Unstuck(std::mutex& mtx,std::condition_variable& cv, bool& flag);
    double getVolacity();
    void setVolacity(double volacity);
    int getXPosition();
    void setXPosition(int x_position);
    int getYPosition();
    void setYPosition(int y_position);
    bool getGoDown();
    void setGoDown(bool goDown);
    bool getGoRight();
    void setGoRight(bool goRight);
    std::thread UpdateThread(/*std::mutex& mtx,std::condition_variable& cv, bool& flag*/);
    //std::thread UnstuckThread();
    static void setRunningFlag(bool flag);
    static bool getRunningFlag();
};

#endif