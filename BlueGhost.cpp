//
// Created by zaeem on 2018/01/27.
//

#include <stdexcept>
#include "BlueGhost.h"

BlueGhost::BlueGhost(int myX, int myY, int spd) {
    uTile = makeTile(myX, myY, GhostB, Up);
    dTile = makeTile(myX, myY, GhostB, Down);
    lTile = makeTile(myX, myY, GhostB, Left);
    rTile = makeTile(myX, myY, GhostB, Right);
    x = myX; y = myY;
    speed = spd;
}

SDL_Rect BlueGhost::DetermineTarget(pacman myPacman, std::pair<int, int> red,
                                    std::vector<std::vector<Tile>> maze) {

    if (!maze[myPacman.y][myPacman.x].isOfTileType(Pacman)) {
        throw std::invalid_argument ("Blue: That's not pacman's tile :(");
    }

    if (!maze[red.first][red.second].isOfTileType(GhostR)) {
        throw std::invalid_argument ("Blue: That's not red's tile :(");
    }


}

mazeIndex BlueGhost::getRequiredIndexFromPacman(pacman myPacman, int numTilesAway,
                                                         std::vector<std::vector<Tile>> maze) {

    //initialze with pacman's direction and exact index
    Direction direction = myPacman.dir;
    mazeIndex curr_req_index = getMazeIndex(myPacman.x, myPacman.y);

    for (int i = 0; i < numTilesAway; ++i) {
        // get next index based on direction
        mazeIndex nextIndex = getNextTileIndex(curr_req_index, direction);

        // if index is out of bounds or is not a blank (valid) tile
        if (!isAValidMove(nextIndex, maze)) {

            mazeIndex ghostIndex = getMazeIndex(x, y);
            mazeIndex pacmanIndex = getMazeIndex(myPacman.x, myPacman.y);

            // set new direction based on which directiin we couldn't go to before
            if (direction == Left || direction == Right) {
                mazeIndex upIndex = getNextTileIndex(curr_req_index, Up);
                mazeIndex downIndex = getNextTileIndex(curr_req_index, Down);
                if (isAValidMove(upIndex, maze) && isAValidMove(downIndex, maze))
                    direction = (ghostIndex.row > pacmanIndex.row)? Up : Down;
                else if (curr_req_index.row - 1 >= 0)
                    direction = Up;
                else
                    direction = Down;
            } else {
                if (curr_req_index.col - 1 >= 0 && curr_req_index.col + 1 < maze[0].size())
                    direction = (ghostIndex.col > pacmanIndex.col)? Right : Left;
                else if (curr_req_index.col - 1 >= 0)
                    direction = Left;
                else
                    direction = Right;
            }

            nextIndex = getNextTileIndex(curr_req_index, direction);
        }

        curr_req_index = nextIndex;
    }

    return curr_req_index;
}

mazeIndex BlueGhost::getNextTileIndex(mazeIndex curr, Direction dir) {
    mazeIndex next = curr;
    if (dir == Up)
        next.row -= 1;
    else if (dir == Down)
        next.row += 1;
    else if (dir == Left)
        next.col -= 1;
    else
        next.col += 1;

    return next;
}