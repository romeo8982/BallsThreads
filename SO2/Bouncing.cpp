#include "Bouncing.h"

void Bouncing::BouncingBall(int &position_x, int &position_y, bool &go_down, bool &go_right)
{
	if(position_y<=23&!go_down)
	{
		position_y--;
		if(position_y<=0) go_down=true;
	}
	if(position_y<23&go_down)
	{
		position_y++;
		if(position_y>=23) go_down=false;
	}
	if(position_x<=79&!go_right)
	{
		position_x--;
		if(position_x<=0) go_right=true;
	}
	if(position_x<79&go_right)
	{
		position_x++;
		if(position_x>=79) go_right=false;
	}
}