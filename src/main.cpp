#include "raylib.h"
#include "resource_dir.h"
#include "player.h"
#include "global.h"
#include <iostream>

Vector2 handle_hit(Vector2 playerpos, Vector2 ballpos)
{
	if(playerpos.y - ballpos.y < 1 && playerpos.x - ballpos.x < 20)
		return {0, -1};
	else if(abs(playerpos.y - ballpos.y) > 1000)
		return {0, 1};
	return {0, 0};
}


int handle_ball(Vector2 *position, Vector2 playerpos, float speed)
{
	float ballradius = 10;
	Vector2 velocity = handle_hit(*position, playerpos);
	Vector2 init_pos = {position->x + speed * velocity.x, position->y + speed * velocity.y};

	DrawCircle(init_pos.x, init_pos.y, ballradius, WHITE);
	*position = init_pos;
	return 0;
}


int main ()
{
	//SETUP
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "AtariBreakout");
	SearchAndSetResourceDir("resources");


	Vector2 playerpos = {WINDOWWIDTH/2, WINDOWHEIGHT - 50};
	float speed = 10;
	Vector2 circlepos = {WINDOWWIDTH/2, WINDOWHEIGHT/2};


	//LOOP
	while (!WindowShouldClose())
	{
		
		BeginDrawing();
		ClearBackground(BLACK);
		handle_ball(&circlepos, playerpos, speed/2);
		move_controller(&playerpos, speed);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
