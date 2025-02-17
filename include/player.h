#include "raylib.h"
#include "global.h"



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
