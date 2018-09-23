//
// Created by zaeemasvat_ on 2018/09/20.
//

#ifndef PACMAN_LOADLEVELHELPERS_H
#define PACMAN_LOADLEVELHELPERS_H


#include <string>
#include "world.h"

struct loadLevelHelpers {
    World loadLevelOne(std::string maze_file, int tileWidth, int tileHeight);
};


#endif //PACMAN_LOADLEVELHELPERS_H
