#include <ncurses.h>
#include <vector>
#include "Ball.h"
class Draw
{
    int x,y;
    WINDOW * inputwin;
    public:
    Draw();
    ~Draw();
    bool Exit();
    void Border();
    void Move(std::vector <Ball> balls);
};
