#include "Draw.h"
#include <unistd.h>
#include "Mutex.h"
Draw::Draw()
{
    initscr();
    noecho();
    curs_set(0);
    inputwin = newwin(16,51,0,0);
    clear();
    refresh();
}
Draw::~Draw()
{
    endwin();
}
void Draw::Border()
{
    for(int i = 0; i < 51; i++){

            //top border
            mvaddch(0,i,'-');
            //bottom border
            mvaddch(16,i,'-');
    }
    for(int i = 0; i < 16; i++){

            //left border
            mvaddch(i,0,'|');
            //right border
            mvaddch(i,51,'|');
    }
}
void Draw::Move(std::vector <Ball*> balls)
{
    
    int row,col;
    
    clear();
    Border();
    getmaxyx(stdscr,row,col);
    
    for(int i=0;i<balls.size();i++)
    {
        if(balls[i]->getXPosition()<row & balls[i]->getYPosition()<col)
        {
            move(balls[i]->getXPosition(),balls[i]->getYPosition());
            printw("O");
        }
        else
        {
            printw("Invalid Argument");
        }
    }
    //getch();
    refresh();
    usleep(50000);
}
