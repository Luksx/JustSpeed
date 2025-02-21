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

int MoveController(Rectangle *playerrec, int playerid, float game_speed)
{
	Vector2 velocity = check_movement(playerid);
	int init_x = playerrec->x + game_speed * velocity.x;
	if(init_x > (WINDOWWIDTH - 10 - PLAYERY) || init_x < (10 + PLAYERY));
	else
	playerrec->x = init_x;
	playerrec->y =  playerrec->y + game_speed * velocity.y;

	DrawRectangleRec(*playerrec, WHITE);
	return 0;
}
