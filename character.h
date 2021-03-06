#ifndef CHARACTER_H
#define CHARACTER_H

#include "tile.h"
#include "mazeIndex.h"

class Character
{
public:

	Character();

    virtual void render(Texture *t, int frame);

    SDL_Rect getNextPosition();

	void setDirection (Direction d);
	Direction getDrection();

    int x, y;

    Direction dir = Left;

    Tile uTile;
    Tile dTile;
    Tile lTile;
    Tile rTile;

	virtual void assignTilePos (SDL_Rect rec);

	mazeIndex getMazeIndex ();
	mazeIndex getFloorMazeIndex ();
	mazeIndex getCeilMazeIndex();

	void setSpeed (int new_spd);
	int getSpeed();

protected:
	int speed; //pixels per timestep

    mazeIndex getMazeIndex(int some_x, int some_y);
    mazeIndex getFloorMazeIndex (int some_x, int some_y);
};

#endif // CHARACTER_H
