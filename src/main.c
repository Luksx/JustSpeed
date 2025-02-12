#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir


#define WINDOWHEIGHT 1280
#define WINDOWWIDTH 800

Vector2 check_movement(){
	Vector2 velocity = {0,0};
	if(IsKeyDown(KEY_S)){
		velocity.y += 1;
	}
	if(IsKeyDown(KEY_W)){
		velocity.y -= 1;
	}
	if(IsKeyDown(KEY_D)){
		velocity.x += 1;
	}
	if(IsKeyDown(KEY_A)){
		velocity.x -= 1;
	}
	return velocity;
}

int move_controller(Vector2 *position, float speed){
	Vector2 velocity = check_movement();
	Vector2 init_pos = {position->x + speed * velocity.x, position->y + speed * velocity.y};
	DrawRectangle(init_pos.x, init_pos.y, 64, 32, WHITE);
	*position = init_pos;
}



int main ()
{
	//SETUP
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "AtariBreakout");
	SearchAndSetResourceDir("resources");


	Vector2 playerpos = {WINDOWWIDTH/2, WINDOWHEIGHT/2};
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
