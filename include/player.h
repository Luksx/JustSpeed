#include "raylib.h"
#include "global.h"
#include <iostream>



Vector2 check_movement(int playerid){
	Vector2 velocity = {0, 0};

	if(playerid){
		if(IsKeyDown(KEY_RIGHT)){
			velocity.x += 1;
		}
		if(IsKeyDown(KEY_LEFT)){
			velocity.x -= 1;
			}
	}
	else{

		if(IsKeyDown(KEY_D)){
			velocity.x += 1;
		}
		if(IsKeyDown(KEY_A)){
			velocity.x -= 1;
		}
	}
	return velocity;
}

int move_controller(Vector2 *position, int playerid, float game_speed,Vector2 playersize)
{
	Vector2 velocity = check_movement(playerid);
	Vector2 init_pos = {position->x + game_speed * velocity.x, position->y + game_speed * velocity.y};
	//Check borders
	if(init_pos.x > (WINDOWWIDTH-10 -playersize.x) || init_pos.x < (10))
	init_pos = *position;

	DrawRectangle(init_pos.x, init_pos.y, playersize.x, playersize.y, WHITE);
	*position = init_pos;
	return 0;
}
