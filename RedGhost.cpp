//
// Created by zaeem on 2018/01/24.
//

#include "RedGhost.h"

RedGhost::RedGhost(int myX, int myY, int spd) {
    uTile = makeTile(myX, myY, GhostR, Up);
    dTile = makeTile(myX, myY, GhostR, Down);
    lTile = makeTile(myX, myY, GhostR, Left);
    rTile = makeTile(myX, myY, GhostR, Right);
    x = myX; y = myY;
    speed = spd;
}
