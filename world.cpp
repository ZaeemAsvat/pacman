#include "world.h"
#include "helpers.h"
#include "character.h"

#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

using namespace std;
/**
 * Constructs the World object loading a maze from the supplied file.
 * It should initialise the \ref{map} array with the relevant tiles as well
 * as the pacman and ghost objects.
 *
 * @param filename - File from which the maze should be read.
 * @param tileWidth - Width of each tile
 * @param tileHeight - Height of each tile
 */
World::World(string filename, int tileWidth, int tileHeight)
        : food(0), points(0), ready(true), myPacman(0,0, 5), Red(0,0, GhostR, 5), Blue(0,0, GhostB, 5)
{
    ifstream f(filename);
    if(!f.is_open()) {
        throw runtime_error("Couldn't open maze file " + filename);
    }

    // Code to read in the file...
    f >> rows >> cols;
    maze.resize(rows);
    char currC;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            f >> currC;

            //create food tile
            if (currC == '.') {
                maze[r].push_back (makeTile(c*tileWidth, r*tileHeight, Food));
                ++food;
            }

                //create black tile for pacman
            else if (currC == '0') {
                maze[r].push_back (makeTile(c*tileWidth, r*tileHeight, Blank));

                myPacman.x = c*tileWidth;
                myPacman.y = r*tileHeight;

                myPacman.uTile.x = c*tileWidth;
                myPacman.uTile.y = r*tileHeight;
                myPacman.dTile.x = c*tileWidth;
                myPacman.dTile.y = r*tileHeight;
                myPacman.lTile.x = c*tileWidth;
                myPacman.lTile.y = r*tileHeight;
                myPacman.rTile.x = c*tileWidth;
                myPacman.rTile.y = r*tileHeight;

            }


                //create Wall tile
            else if (currC == 'x') {
                maze[r].push_back (makeTile(c*tileWidth, r*tileHeight, Wall));
            }

            else if (currC == 'H') {
                maze[r].push_back(makeTile(c*tileWidth, r*tileHeight, GhostHome));
            }

                //creates blank tile for ghosts and blank tiles
            else if (currC == 'R') {
                maze[r].push_back (makeTile(c*tileWidth, r*tileHeight, Blank));
                Red.x = c*tileWidth;
                Red.y = r*tileHeight;
            }

            else if (currC == 'B') {
                maze[r].push_back (makeTile(c*tileWidth, r*tileHeight, Blank));
                Blue.x = c*tileWidth;
                Blue.y = r*tileHeight;
            }

            else if (currC == 'P') {
                maze[r].push_back (makeTile(c*tileWidth, r*tileHeight, Blank));
                Pink.x = c*tileWidth;
                Pink.y = r*tileHeight;
            }

            else if (currC == 'O') {
                maze[r].push_back (makeTile(c*tileWidth, r*tileHeight, Blank));
                Yellow.x = c*tileWidth;
                Yellow.y = r*tileHeight;
            }

            else if (currC == ' ') {
                maze[r].push_back (makeTile(c*tileWidth, r*tileHeight, Blank));
            }

            else throw std::runtime_error ("maze contains invalid characters");
        }
    }
}

/**
 * Renders the World to the ::sdlRenderer buffer.
 * It calls the respective render functions on each tile first.
 * Following this, it calls the pacman and ghost objects to render
 * them above the background.
 * @param frame [optional] An optional frame number to pass to the objects to handle animation.
 */
void World::render(Texture *t, int frame)
{
    for (auto r : maze) {
        for (auto e : r) {
            e.render(t,frame);
        }
    }

    //render pacman
    myPacman.render(t, frame);
}

/**
 * This function is responsible for advancing the game state.
 * Pacman and the ghosts should be moved (if possible). If pacman is
 * captured by a ghost pacman.dead should be set to true. If pacman eats
 * a food pellet the relevant totals should be updated.
 *
 * @return The same value as W
orld::ready, indicating whether the game is finished.
 */
bool World::UpdateWorld()
{
    ready = points != food*10;
    //next position of pacman on the screen

    updatePacman();

    return ready;

}

void World::updatePacman() {
    SDL_Rect nextPos;
    bool pendingMoveMade = false;

    // if we have a move pending
    if (myPacman.movePending) {

        SDL_Rect pendingPos = myPacman.getNextPosition();

        //if pending move is valid
        if (!collidedWithWall(pendingPos)) {
            myPacman.dir = myPacman.pendingDir;
            nextPos = myPacman.getNextPosition();
            myPacman.pendingDir = NoDirection;
            myPacman.movePending = false;
            pendingMoveMade = true;

            myPacman.assignTilePos(nextPos);
            handleEating(nextPos);
        }
    }

    if (!pendingMoveMade) {

        nextPos = myPacman.getNextPosition();
        //whether or not we hit a wall or edge
        bool collidedW = this->collidedWithWall(nextPos);

        if (collidedW) {

            //pacman changed direction when about to collide with a wall
            if (myPacman.dir != myPacman.prevDir) {
                myPacman.movePending = true;
                myPacman.pendingDir = myPacman.dir;
            }

            myPacman.dir = myPacman.prevDir;

        } else {

            //pacman changed direction
            if (myPacman.dir != myPacman.prevDir) {
                myPacman.pendingDir = NoDirection;
                myPacman.movePending = false;
            }

            myPacman.assignTilePos(nextPos);
            handleEating(nextPos);
        }
    }

    myPacman.prevDir = myPacman.dir;

}

void World::updateGhosts() {

    // only Red Ghost for now

    SDL_Rect next;

    if (!Red.isActive()) {
        next = handleInactivity();
    } else {

        if (Red.hasBeenEaten()) {

            // try to get the ghost into its home, handle inactivity once there
            if (Red.getFloorMazeIndex() != ghost::getHome()[Down])
                next = getNextPosition(ghost::getHome()[Down]);
            else
                next = handleInactivity();

        } else if (Red.isFrightened() || Red.isLosingFright())
            next = handleFrightened();

        else next = ghost::getMode() == Scatter ? handleScatterMode() : handleChaseMode();
    }

    Red.assignTilePos(next);
}

SDL_Rect World::handleChaseMode() {

    SDL_Rect next = getNextPosition(myPacman.getMazeIndex());

    GhostPlan ghostPlan = ghost::getGhostPlan();
    if (ghostPlan.hasPendingScztterPeriod()) {
        if (ghost_timer.getTicks() >= ghostPlan.getCurrScatter().getStart()) {
            ghost::setMode(Scatter);
            next = handleScatterMode();
        }
    }

    return next;
}

SDL_Rect World::handleScatterMode() {

    SDL_Rect next;

    GhostPlan ghostPlan = ghost::getGhostPlan();
    GhostScatterPeriod curr_scatter_period = ghostPlan.getCurrScatter();

    if (ghost_timer.getTicks() >= curr_scatter_period.getStart() + curr_scatter_period.getDuration()) {

        ghost::setMode(Chase);
        ghostPlan.goToNextScatterPeriod();
        next = handleChaseMode();

    } else {

        if (Red.getCurrScatterTargetIndex() == -1)
            Red.setCurrScatterTarget(0);

        if (Red.getMazeIndex() == Red.getCurrScatterTargetIndex())
            Red.setCurrScatterTarget(Red.getCurrScatterTargetIndex() == 0 ? 1 : 0);

        next = getNextPosition(Red.getCurrScatterTargetIndex());
    }

    return next;
}

SDL_Rect World::handleFrightened() {

    SDL_Rect next;

    if (Red.isFrightened()) {

        if (!ghost_timer.isPaused())
            ghost_timer.pause();

        if (!frightened_timer.isStarted())
            frightened_timer.start();

        if (frightened_timer.getTicks() >= ghost::getGhostPlan().getFrightenedDuration()) {
            frightened_timer.stop();
            Red.setFrightened(false);
            Red.setLosingFright(true);
        }
    }

    if (Red.isLosingFright()) {
        if (!frightened_timer.isStarted())
            frightened_timer.start();

        if (frightened_timer.getTicks() >= ghost::getGhostPlan().getFrightenedDuration()) {
            frightened_timer.stop();
            ghost_timer.unpause();
            Red.setLosingFright(false);

            next = ghost::getMode() == Scatter ? handleScatterMode() : handleChaseMode();
        }
    }

    if (Red.isFrightened() || Red.isLosingFright()) {

        std::vector<SDL_Rect> possible_next_positions;

        std::array<mazeIndex, 4> possible_indices = {getNextMazeIndex(Red, Up),
                                                     getNextMazeIndex(Red, Down),
                                                     getNextMazeIndex(Red, Left),
                                                     getNextMazeIndex(Red, Right)};

        Direction opposite_dir_to_current = getOppositeDirection(Red.getDrection());

        for (int i = 0; i < possible_indices; ++i) {

            if (isWithinBounds(possible_indices[i])
                && !maze[possible_indices[i].row][possible_indices[i].col].isOfTileType(Wall)
                && !maze[possible_indices[i].row][possible_indices[i].col].isOfTileType(GhostHome)
                && i != opposite_dir_to_current) {

                possible_next_positions.push_back({possible_indices[i].col * 20, possible_indices[i].row * 20, 20, 20});
            }

        }

        if (possible_next_positions.empty())
            throw std::runtime_error("can't find random move for Red ghost!");

        next = possible_next_positions[getRandomNumber(0, possible_next_positions.size() - 1);

    }

    return next;
}

SDL_Rect World::handleInactivity() {

    SDL_Rect next;

    if (!red_inactive_timer.isStarted())
        red_inactive_timer.start();

    Red.setActive(false);

    Uint32 inactive_duration = Red.hasBeenEaten() ? Red.getGhostPlan().getInactiveOnceBittenDuration() : Red.getGhostPlan().getInitialInactiveDuration();

    if (red_inactive_timer.getTicks() >= inactive_duration) {

        red_inactive_timer.stop();
        Red.setActive(true);
        Red.setEaten(false);

        next = ghost::getMode() == Scatter ? handleScatterMode() : handleChaseMode();

    } else {

        if (!(Red.getDrection() == Left || Red.getDrection() == Right))
            Red.setDirection(Left);

        next = Red.getNextPosition();
        if (next.x / 20 < ghost::getHome()[Left].col || next.x / 20 > ghost::getHome()[Right].col) {
            Red.setDirection(Red.getDrection() == Left ? Right : Left);
            next = Red.getNextPosition();
        }
    }

    return next;
}

SDL_Rect World::getNextPosition(mazeIndex target) {
    Red.setTarget(target);
    Red.bfs(maze);
    Red.UpdateDirection();
    return Red.getNextPosition();
}

bool World::isWithinBounds(mazeIndex index) {
    return index.row >= 0 && index.row < maze.size() && index.col >= 0 && index.col < maze[0].size();
}

Direction World::getOppositeDirection(Direction d) {

    switch (d) {
        case Up:
            return Down;
        case Down:
            return Up;
        case Left:
            return Right;
        default:
            return Left;
    }
}

int World::getRandomNumber(int low, int high) {
    srand(time(0));
    return rand() % high + low;
}

mazeIndex World::getFloorIndex(int x, int y) {
    return mazeIndex (std::floor(y/20), std::floor (x/20));
}

mazeIndex World::getCeilingIndex(int x, int y) {
    return mazeIndex (std::ceil(y/20), std::ceil(x/20));
}

mazeIndex World::getNextMazeIndex(ghost my_ghost, Direction d) {

    switch (d) {
        case Left:
            return getFloorIndex(my_ghost.x - my_ghost.getSpeed(), my_ghost.y);
        case Right:
            return getCeilingIndex(my_ghost.x + my_ghost.getSpeed(), my_ghost.y);
        case Up:
            return getFloorIndex(my_ghost.x, my_ghost.y - my_ghost.getSpeed());
        case Down:
        default:
            return getCeilingIndex(my_ghost.x, my_ghost.y + my_ghost.getSpeed());
    }
}

SDL_Rect getNextPosition (ghost my_ghost, Direction d) {

    SDL_Rect curr = {my_ghost.x, my_ghost.y, 20, 20};

    if (d == Left)
        curr.x -= my_ghost.getSpeed();
    else if (d == Right)
        curr.x += my_ghost.getSpeed();
    else if (d == Up)
        curr.y -= my_ghost.getSpeed();
    else
        curr.y += my_ghost.getSpeed();

    return curr;
}

bool World::collidedWithWall(SDL_Rect rec) {

    if (rec.x < 0 || rec.y < 0 || rec.y > rows*20 || rec.x > cols*20)
        return true;

    for (auto r : maze) {
        for (auto t : r) {
            if (t.myType == Wall && collision(rec, {t.x, t.y, t.w*20, t.h*20}, 0, 0)) {
                return true;
            }
        }
    }


    return false;
}

void World::handleEating (SDL_Rect rec) {
    bool ate = false;
    for (auto &r : maze) {
        if (ate) {
            break;
        } else {
            for (auto &t : r) {
                if (t.myType == Food && collision(rec, {t.x, t.y, t.w*20, t.h*20}, 5, 5)) {
                    t = makeTile(t.x, t.y, Blank);
                    points += 10;
                    cout << points << endl;
                    ate = true;
                    break;
                }
            }
        }
    }
}


