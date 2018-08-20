#include <cmath>
#include <iostream>
#include "ghost.h"

ghost_mode ghost::mode = Chase;
std::array<mazeIndex, 4> ghost::homeIndices;

ghost::ghost(int myX, int myY, TileType t, int spd) {
    uTile = makeTile(myX, myY, t, Up);
    dTile = makeTile(myX, myY, t, Down);
    lTile = makeTile(myX, myY, t, Left);
    rTile = makeTile(myX, myY, t, Right);
    x = myX; y = myY;
    speed = spd;
}

ghost::ghost() {}

void ghost::setsHome(mazeIndex up, mazeIndex down, mazeIndex left, mazeIndex right) {
    homeIndices[HomeUpIndex] = up;
    homeIndices[HomeDownIndex] = down;
    homeIndices[HomeLeftIndex] = left;
    homeIndices[HomeRightIndex] = right;
}

std::array<mazeIndex, 4> ghost::getHome() {
    return homeIndices;
}

void ghost::setScatterRec(mazeIndex t_right, mazeIndex t_Left, mazeIndex b_left, mazeIndex b_right) {
    ScatterRec[TopRight] = t_right;
    ScatterRec[TopLeft] = t_Left;
    ScatterRec[BottomLeft]= b_left;
    ScatterRec[BottomRight] = b_right;
}

std::array<mazeIndex, 4> ghost::getScatterRec() {
    return ScatterRec;
}

void ghost::setTarget(mazeIndex target) {
    TargetIndex = target;
}

void ghost::assignTilePos(SDL_Rect rec) {
    x = rec.x;
    y = rec.y;

    if (!isActive())
        Character::assignTilePos(rec);
    else {
        if (hasBeenEaten()) {
            eatenUTile.x = x;
            eatenUTile.y = y;
            eatenDTile.x = x;
            eatenDTile.y = y;
            eatenLTile.x = x;
            eatenLTile.y = y;
            eatenRTile.x = x;
            eatenRTile.y = y;
        } else {
            ghost_mode currMode = getMode();
            switch (currMode) {
                case Chase:
                    Character::assignTilePos(rec); break;
                case Scatter:
                    Character::assignTilePos(rec); break;
                case Frightened:
                    frightenedTile.x = x;
                    frightenedTile.y = y;
                    break;
                case LosingFright:
                default:
                    losingFrightTile.x = x;
                    losingFrightTile.y = y;
                    break;
            }
        }
    }
}

void ghost::setEaten(bool eaten) {
    eaten = true;
}

bool ghost::hasBeenEaten() {
    return eaten;
}

void ghost::render(Texture *t, int frame) {

    if (!isActive())
        Character::render(t, frame);
    else {
        if (hasBeenEaten()) {
            switch (dir) {
                case Up:
                    eatenUTile.render(t, frame); break;
                case Down:
                    eatenDTile.render(t, frame); break;
                case Left:
                    eatenLTile.render(t, frame); break;
                case Right:
                default:
                    eatenRTile.render(t, frame); break;
            }
        } else {

            ghost_mode currMode = getMode();

            if (currMode == Chase || currMode == Scatter)
                Character::render(t, frame);
            else if (currMode == Frightened)
                frightenedTile.render(t, frame);
            else
                losingFrightTile.render(t, frame);
        }
    }
}

void ghost::bfs (std::vector<std::vector<Tile>> maze) {

    mazeIndex start = getMazeIndex();

    std::vector<std::vector<mazeIndex>> parent (maze.size(), std::vector<mazeIndex> (maze[0].size()));
    parent[start.row][start.col] = {-2, -2};

    std::vector<std::vector<bool>> discovered (maze.size(), std::vector<bool> (maze[0].size(), false));

    std::queue<mazeIndex> q;
    q.push(start);

    discovered[start.row][start.col] = true;

    bool Goalfound = start == TargetIndex;

    while (!q.empty() && !Goalfound) {
        mazeIndex curr = q.front();
        q.pop();

        if (curr == TargetIndex) {
            Goalfound = true;
        } else {
            mazeIndex temp;

            //below
            temp = {curr.row + 1, curr.col};
            if (temp.row < maze.size() && !maze[temp.row][temp.col].isOfTileType(Wall) && !discovered[temp.row][temp.col]) {
                parent[temp.row][temp.col] = curr;
                discovered[temp.row][temp.col] = true;
                q.push(temp);
            }

            // left
            temp = {curr.row, curr.col-1};
            if (temp.col >= 0 && !maze[temp.row][temp.col].isOfTileType(Wall) && !discovered[temp.row][temp.col]) {
                parent[temp.row][temp.col] = curr;
                discovered[temp.row][temp.col] = true;
                q.push(temp);
            }


            // up
            temp = {curr.row - 1, curr.col};
            if (temp.row >= 0 && !maze[temp.row][temp.col].isOfTileType(Wall) && !discovered[temp.row][temp.col]) {
                parent[temp.row][temp.col] = curr;
                discovered[temp.row][temp.col] = true;
                q.push(temp);
            }


            // right
            temp = {curr.row, curr.col + 1};
            if (temp.col < maze[0].size() && !maze[temp.row][temp.col].isOfTileType(Wall) && !discovered[temp.row][temp.col]) {
                parent[temp.row][temp.col] = curr;
                discovered[temp.row][temp.col] = true;
                q.push(temp);
            }
        }
    }

    ghostPath = {{false}};
    if (!q.empty() || Goalfound) {
        mazeIndex curr = parent[TargetIndex.row][TargetIndex.col];
        while (curr != start) {
            ghostPath[curr.row][curr.col] = true;
            curr = parent[curr.row][curr.col];
        }
    }
}

bool ghost::isWithinRange(mazeIndex i, int max_width, int max_height) {
    return i.row >= 0 && i.row < max_height && i.col >= 0 && i.col < max_width;
}

bool ghost::isAValidMove(mazeIndex i, std::vector<std::vector<Tile> > maze) {
    return isWithinRange(i, maze[0].size(), maze.size()) && maze[i.row][i.col].isOfTileType(Blank);
}

void ghost::setMode(ghost_mode m) {
    mode = m;
}

ghost_mode ghost::getMode() {
    return mode;
}

int ghost::round(int x, int n) {
    return std::round(x/n) * n;
}

void ghost::UpdateDirection() {
    mazeIndex mazeindex = getMazeIndex();

    if (ghostPath[mazeindex.row][mazeindex.col - 1] == true)
        dir = Left;
    else if (ghostPath[mazeindex.row][mazeindex.col + 1] == true)
        dir = Right;
    else if (ghostPath[mazeindex.row + 1][mazeindex.col] == true)
        dir = Down;
    else if (ghostPath[mazeindex.row - 1][mazeindex.col] == true)
        dir = Up;
    else
        throw std::runtime_error("Ghost has no path!");
}

bool ghost::isActive() {
    return active;
}

void ghost::setActive(bool a) {
    active = a;
}

void ghost::setGhostPlan(GhostPlan p) {
    plan = p;
}

GhostPlan ghost::getGhostPlan() {
    return plan;
}