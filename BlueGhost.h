//
// Created by zaeem on 2018/01/27.
//

#ifndef PACMAN_BLUEGHOST_H
#define PACMAN_BLUEGHOST_H

#include "ghost.h"
#include "pacman.h"

class BlueGhost : public ghost {

public:
    BlueGhost (int x, int y, int spd);

    SDL_Rect DetermineTarget(pacman myPacman, std::pair<int, int> red, std::vector<std::vector<Tile>> maze);

private:
    mazeIndex getRequiredIndexFromPacman (pacman myPacman, int numTilesAway, std::vector<std::vector<Tile>> maze);
    mazeIndex getNextTileIndex (mazeIndex curr, Direction dir);
};


#endif //PACMAN_BLUEGHOST_H
