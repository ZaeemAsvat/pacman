#include <cmath>
#include "tile.h"
#include "helpers.h"
#include "character.h"

Character::Character() {}
	

/**
 * @brief Character::render Call the relevant tiles render function based on current direction.
 * @param t Texture object for rendering.
 * @param frame Frame number to render.
 */
void Character::render(Texture *t, int frame)
{
	if (dir == Up) {
		uTile.render(t, frame);
	} else if (dir == Down) {
		dTile.render(t, frame);
	} else if (dir == Left) {
		lTile.render(t, frame);
	} else {
		rTile.render(t, frame);
	}	
}
/**
 * @brief Character::getNextPosition Calculates the position of the character based on direction.
 * @return SDL_Rect of the position and dimensions (in pixels) of the character.
 */
SDL_Rect Character::getNextPosition()
{
	SDL_Rect temp = {x, y, 20, 20};
	if (dir == Up)
		 temp.y -= speed;
	else if (dir == Down)
		temp.y += speed;
	else if (dir == Left)
		temp.x -= speed;
	else
		temp.x += speed;

	return temp;
}


void Character::assignTilePos (SDL_Rect rec) {
	
	x = rec.x;
	y = rec.y;

	uTile.x = x;
	uTile.y = y;
	dTile.x = x;
	dTile.y = y;
	lTile.x = x;
	lTile.y = y;
	rTile.x = x;
	rTile.y = y;
}

void Character::setSpeed(int new_spd) {
	speed = new_spd;
}

int Character::getSpeed() {
	return speed;
}

void Character::setDirection(Direction d) {
	dir = d;
}

Direction Character::getDrection() {
	return dir;
}

mazeIndex Character::getMazeIndex() {
	return mazeIndex (((x+10)/20) * 20, ((y+10)/20) * 20);
}

mazeIndex Character::getFloorMazeIndex() {
	return mazeIndex (y/20, x/20);
}

mazeIndex Character::getMazeIndex(int some_x, int some_y) {
    return mazeIndex (((some_x+10)/20) * 20, ((some_y+10)/20) * 20);
}

/*

void Character::setPendingPosition(Direction pDir) {

	if (pDir == NoDirection) {
		pendingPosition.x = x;
		pendingPosition.y = y;
	} else {

		if (pDir == Up) {
			 pendingPosition.y = y - 5;
		} else if (pDir == Down) {
			pendingPosition.y = y + 5;
		} else if (pDir == Left) {
			pendingPosition.x = x - 5;
		} else {
			pendingPosition.x = x + 5;
		}
	}
}

void Character::resetPendingVars() {
	pendingDir = NoDirection;
	penDistance = 0;
	setPendingPosition(NoDirection);
}

*/
