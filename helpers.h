#ifndef SDL_HELPERS_H
#define SDL_HELPERS_H

#include "tile.h"
#include "ghost.h"

Tile makeTile(int x, int y, TileType t, Direction dir = Up);
bool collision(SDL_Rect a, SDL_Rect b, int a_off = 0, int b_off = 0);

#endif // SDL_HELPERS_H
