#include "raylib.h"
#include "global.h"
#include <iostream>


int BorderCollide(Vector2 ballpos)
{
	return (ballpos.x < 0 || ballpos.x > WINDOWWIDTH-BALLSIZE);
}

int GateCollide(Vector2 ballpos)
{
	return (ballpos.y < 0 || ballpos.y > WINDOWHEIGHT);
}

int HandleBall(Rectangle player1rec, Rectangle player2rec, Vector2 *ballpos, Vector2 *prevelocity, int * ballhits)
{
	if(CheckCollisionCircleRec(*ballpos, BALLSIZE, player1rec) || CheckCollisionCircleRec(*ballpos, BALLSIZE, player2rec))
	{
		float random_x = (drand48() - 1.5)/2;
		*prevelocity = {prevelocity->x + random_x, -prevelocity->y};
		*ballhits++;
	}
	else if(BorderCollide(*ballpos))
	prevelocity->x = -prevelocity->x;
	else if(GateCollide(*ballpos))
	*ballpos = {WINDOWWIDTH/2 - BALLSIZE, WINDOWHEIGHT/2 - BALLSIZE};

	ballpos->x += prevelocity->x * GAMESPEED;
	ballpos->y += prevelocity->y * GAMESPEED;
	DrawCircle(ballpos->x, ballpos->y, BALLSIZE, RED);
	return 0;
}
