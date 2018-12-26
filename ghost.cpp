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

    eatenUTile = makeTile(myX, myY, EatenGhost, Up);
    eatenDTile = makeTile(myX, myY, EatenGhost, Down);
    eatenLTile = makeTile(myX, myY, EatenGhost, Left);
    eatenRTile = makeTile(myX, myY, EatenGhost, Right);

    frightenedTile = makeTile(myX, myY, FrightenedGhost);
    losingFrightTile = makeTile(myX, myY, LosingFrightGhost);

    x = myX; y = myY;
    speed = spd;
    mode = Chase;
}

ghost::ghost() {}

void ghost::setsHome(mazeIndex up, mazeIndex down, mazeIndex left, mazeIndex right) {
    homeIndices[HomeUpIndex] = up;
    homeIndices[HomeDownIndex] = down;
    homeIndices[HomeLeftIndex] = left;
    homeIndices[HomeRightIndex] = right;
}

void ghost::setHomeIndex(mazeIndex index, ghostHomeIndexDirection direction) {
    switch (direction) {
        case HomeUpIndex:
            homeIndices[HomeUpIndex] = index;
            break;
        case HomeDownIndex:
            homeIndices[HomeDownIndex] = index;
            break;
        case HomeLeftIndex:
            homeIndices[HomeLeftIndex] = index;
            break;
        case HomeRightIndex:
        default:
            homeIndices[HomeRightIndex] = index;
            break;
    }
}

std::array<mazeIndex, 4> ghost::getHome() {
    return homeIndices;
}

void ghost::setScatterPoints(mazeIndex index1, mazeIndex index2) {
    scatterPoints.first = index1;
    scatterPoints.second = index2;
}

std::pair<mazeIndex, mazeIndex> ghost::getScatterPoints() {
    return scatterPoints;
}

mazeIndex ghost::getCurrScatterTarget() {
    if (currScatterTargetIndex != 0 && currScatterTargetIndex != 1)
        throw std::invalid_argument ("scatter index out of bounds!");

    return currScatterTargetIndex == 0 ? scatterPoints.first : scatterPoints.second;
}

void ghost::setCurrScatterTarget(int index) {
    if (currScatterTargetIndex != 0 && currScatterTargetIndex != 1)
        throw std::invalid_argument ("scatter index out of bounds!");

    currScatterTargetIndex = index;
}

int ghost::getCurrScatterTargetIndex() {
    if (currScatterTargetIndex != 0 && currScatterTargetIndex != 1)
        throw std::invalid_argument ("scatter index out of bounds!");

    return currScatterTargetIndex;
}

void ghost::setTarget(mazeIndex target) {
    TargetIndex = target;
}

void ghost::assignTilePos(SDL_Rect rec) {
    Character::assignTilePos(rec);

    eatenUTile.x = x;
    eatenUTile.y = y;
    eatenDTile.x = x;
    eatenDTile.y = y;
    eatenLTile.x = x;
    eatenLTile.y = y;
    eatenRTile.x = x;
    eatenRTile.y = y;

    frightenedTile.x = x;
    frightenedTile.y = y;

    losingFrightTile.x = x;
    losingFrightTile.y = y;
}

void ghost::setEaten(bool e) {
    eaten = e;
}

bool ghost::hasBeenEaten() {
    return eaten;
}

void ghost::ResetGhostPath(int num_rows, int num_cols) {
    ghostPath = std::vector<std::vector<bool>> (num_rows, std::vector<bool> (num_cols, false));
}

void ghost::render(Texture *t, int frame) {

    if (!isActive() || ghost::getMode() == Scatter || ghost::getMode() == Chase)
        Character::render(t, frame);
    else if (hasBeenEaten()) {
        switch (dir) {
            case Up:
                eatenUTile.render(t, frame);
                break;
            case Down:
                eatenDTile.render(t, frame);
                break;
            case Left:
                eatenLTile.render(t, frame);
                break;
            case Right:
            default:
                eatenRTile.render(t, frame);
                break;
        }
    } else if (isFrightened())
        frightenedTile.render(t, frame);
    else if (isLosingFright())
        losingFrightTile.render(t, frame);
    else throw std::runtime_error ("coudn't render ghost! Can't get mode :(");
}

void ghost::setFrightened(bool frightened) {
    this->frightened = frightened;
}

bool ghost::isFrightened() {
    return frightened;
}

void ghost::setLosingFright(bool losing_fright) {
    this->losing_fright = losing_fright;
}

bool ghost::isLosingFright() {
    return losing_fright;
}

void ghost::bfs (std::vector<std::vector<Tile>> maze) {

    mazeIndex start = (dir == Up || dir == Left) ? getCeilMazeIndex() : getFloorMazeIndex();
   // std::cout << start.row << " " << start.col << std::endl;

//   std::cout << "floor: " << getFloorMazeIndex().row << " " << getFloorMazeIndex().col << std::endl;
  //  std::cout << "ceil: " << getCeilMazeIndex().row << " " << getCeilMazeIndex().col << std::endl;

    std::vector<std::vector<mazeIndex>> parent (maze.size(), std::vector<mazeIndex> (maze[0].size()));
    parent[start.row][start.col] = {-2, -2};

    std::vector<std::vector<bool>> discovered (maze.size(), std::vector<bool> (maze[0].size(), false));
    discovered[start.row][start.col] = true;

    std::queue<mazeIndex> q;
    q.push(start);

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

    ResetGhostPath(maze.size(), maze[0].size());

    if (q.empty() || Goalfound) {
        mazeIndex curr = parent[TargetIndex.row][TargetIndex.col];
        while (curr != start) {
            ghostPath[curr.row][curr.col] = true;
            curr = parent[curr.row][curr.col];
        }
        ghostPath[start.row][start.col] = true;
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
    mazeIndex mazeindex = (dir == Left || dir == Up) ? getCeilMazeIndex() : getFloorMazeIndex();

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