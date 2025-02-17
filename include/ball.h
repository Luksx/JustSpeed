#include "raylib.h"
#include <iostream>
#include "global.h"

//player size = 64 x, 32 y

int handle_hit(Vector2 playerpos, Vector2 ballpos, int * ballhits)
{
	if(abs(playerpos.y+16 - ballpos.y) <= 26 && abs(playerpos.x+32 - ballpos.x) <= 42)
	{
		*ballhits = *ballhits + 1;
		return 1;
	}
	return 0;
}

int handle_borderhit(Vector2 ballpos)
{
    if(ballpos.x + BALLSIZE >= WINDOWWIDTH || ballpos.x + BALLSIZE <= 0)
	{
		return 1;	
	}
    else
    return 0;
}

int handle_gameover(Vector2 ballpos)
{
	if(ballpos.y + BALLSIZE >= WINDOWHEIGHT || ballpos.y + BALLSIZE <= 0)
	{
		return 1;	
	}
    else
    return 0;
}


int handle_ball(Vector2 *position, Vector2 playerpos, Vector2 player2pos, float speed, Vector2 *prevelocity, int * ballhits)
{

	Vector2 velocity;
	float random_x = (drand48() - 1.5)/4;
	if(handle_hit(playerpos, *position, ballhits))
	velocity = {(prevelocity->x) + random_x, -(prevelocity->y)};
	else if (handle_hit(player2pos, *position, ballhits))
	velocity = {(prevelocity->x) + random_x, -(prevelocity->y)};
	else{
		velocity =  *prevelocity;
		if (handle_borderhit(*position))
    	velocity.x = -velocity.x;
		if (handle_gameover(*position)){
			*position = {WINDOWWIDTH/2 + 5, WINDOWHEIGHT/2 + 5};
			*prevelocity = {0,-1};
			*ballhits = 0;
		}
	}

	Vector2 init_pos = {position->x + speed * velocity.x, position->y + speed * velocity.y};

	DrawCircle(init_pos.x, init_pos.y, BALLSIZE, WHITE);
	*position = init_pos;
	*prevelocity = velocity;
	return 0;
}
