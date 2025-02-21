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


	Rectangle player1rec = {WINDOWWIDTH/2-32, WINDOWHEIGHT - 50, PLAYERX, PLAYERY};
	Rectangle player2rec = {WINDOWWIDTH/2-32, 50,PLAYERX, PLAYERY};


	

	Vector2 circlepos = {WINDOWWIDTH/2, WINDOWHEIGHT/2};
	Vector2 ball_velocity = {0, 1};

	int ballhits = 0;


	//LOOP
	while (!WindowShouldClose())
	{
		
		BeginDrawing();
		ClearBackground(BLACK);
		
		MoveController(&player1rec, 0, GAMESPEED+(ballhits/3));
		MoveController(&player2rec, 1, GAMESPEED+(ballhits/3));
		HandleBall(player1rec, player2rec, &circlepos, &ball_velocity, &ballhits);
		DrawText(("Ballhits: " + std::to_string(ballhits)).c_str(), 20, 20, 15, WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
