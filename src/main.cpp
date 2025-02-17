#include "raylib.h"
#include "resource_dir.h"
#include "player.h"
#include "global.h"
#include "ball.h"
#include <string>
#include <iostream>



int main ()
{
	//SETUP
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "JustSpeed");
	SearchAndSetResourceDir("resources");

	Vector2 playersize = {64, 32};
	Vector2 playerpos = {WINDOWWIDTH/2-32, WINDOWHEIGHT - 50};
	Vector2 player2pos = {WINDOWWIDTH/2-32, 50};


	Vector2 circlepos = {WINDOWWIDTH/2, WINDOWHEIGHT/2};
	Vector2 ball_velocity = {0, 1};
	float game_speed = 10;

	int ballhits = 1;


	//LOOP
	while (!WindowShouldClose())
	{
		
		BeginDrawing();
		ClearBackground(BLACK);
		handle_ball(&circlepos, playerpos, player2pos, game_speed*((ballhits+1)*GAMESPEEDMOD), &ball_velocity, &ballhits);
		move_controller(&playerpos, 0, game_speed+(ballhits/3), playersize);
		move_controller(&player2pos, 1, game_speed+(ballhits/3), playersize);
		DrawText(("Ballhits: " + std::to_string(ballhits)).c_str(), 20, 20, 15, WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
