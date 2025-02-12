#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir


#define WINDOWHEIGHT 800
#define WINDOWWIDTH 510

Vector2 check_movement(){
	Vector2 velocity = {0,0};
	/*
	if(IsKeyDown(KEY_S)){
		velocity.y += 1;
	}
	if(IsKeyDown(KEY_W)){
		velocity.y -= 1;
	}
	*/
	if(IsKeyDown(KEY_D)){
		velocity.x += 1;
	}
	if(IsKeyDown(KEY_A)){
		velocity.x -= 1;
	}
	return velocity;
}

int move_controller(Vector2 *position, float speed){
	
	Vector2 playersize = {64, 32};


	Vector2 velocity = check_movement();
	Vector2 init_pos = {position->x + speed * velocity.x, position->y + speed * velocity.y};
	//Check borders
	if(init_pos.x > (WINDOWWIDTH-10 -playersize.x) || init_pos.x < (10))
	init_pos = *position;

	DrawRectangle(init_pos.x, init_pos.y, playersize.x, playersize.y, WHITE);
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


	//LOOP
	while (!WindowShouldClose())
	{
		
		BeginDrawing();
		ClearBackground(BLACK);
		move_controller(&playerpos, speed);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
