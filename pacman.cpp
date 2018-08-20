#include "pacman.h"

pacman::pacman (int myX, int myY, int spd) {
    uTile = makeTile(myX, myY, TileType::Pacman, Up);
    dTile = makeTile(myX, myY, TileType::Pacman, Down);
    lTile = makeTile(myX, myY, TileType::Pacman, Left);
    rTile = makeTile(myX, myY, TileType::Pacman, Right);
    x = myX; y = myY;
    speed = spd;
}

void pacman::handle_event(SDL_Event &e)
{
    //storing previous direction
    prevDir = dir;

    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:    dir = Up; break;
            case SDLK_DOWN:  dir = Down; break;
            case SDLK_LEFT:  dir = Left; break;
            case SDLK_RIGHT: dir = Right; break;
        }
    }
}