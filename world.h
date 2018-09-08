#ifndef WORLD_H
#define WORLD_H

/** \file world.h
 * \brief World class header file.
 */

#include "tile.h"
#include "pacman.h"
#include "ghost.h"
#include "timer.h"

/** \brief Represents the entire state of the game.
 *
 * The class stores the maze, pacman, ghosts and is responsible for
 * calling the relevant \ref{render} functions on each object.
 */
class World
{
public:
    int cols;                       ///< Number of columns in the maze (measured in tiles).
    int rows;                       ///< Number of rows in the maze (measured in tiles).
    int food;                       ///< The number of food pellets left in the maze.
    int points;                     ///< The number of food pellets eaten so far.

    bool ready;                     ///< Whether or not the game should continue running for another step.
    /** True: the game can advance another step. False: the game is finished.*/

    pacman myPacman;               ///< Character object representing pacman.\

    ghost Red;
    ghost Blue;
    ghost Pink;
    ghost Yellow;

    std::vector<std::vector<Tile>> maze; ///< Stores maze Tile objects, used to store the background tile states.

    World(std::string filename, int tileWidth, int tileHeight);    ///< Constructor.

    void render(Texture *t, int frame = 0);     ///< Blit all tiles & characters to the ::sdlRenderer.

    bool UpdateWorld();                    ///< Advance the world 1 timestep.

    timer ghost_timer, red_inactive_timer, blue_inactive_timer, yellow_inactive_timer, pink_inactive_timer, frightened_timer;

    mazeIndex myPacman_original_index;

    void resetCharacterPositions();

private:
    bool collidedWithWall(SDL_Rect rec);
    void handleEating (SDL_Rect rec);
    void updatePacman();
    void updateGhosts();

    mazeIndex getFloorIndex (int x, int y);
    mazeIndex getCeilingIndex (int x, int y);
    mazeIndex getNextMazeIndex (ghost my_ghost, Direction d);
    SDL_Rect getNextPosition (ghost my_ghost, Direction d);
    SDL_Rect getRectangle (Tile tile);

    bool isWithinBounds (mazeIndex index);
    Direction getOppositeDirection (Direction d);

    int getRandomNumber (int low, int high);

    SDL_Rect handleChaseMode ();
    SDL_Rect handleFrightened ();
    SDL_Rect handleScatterMode ();
    SDL_Rect handleInactivity();
    SDL_Rect getNextPosition (mazeIndex target);

};

#endif // WORLD_H