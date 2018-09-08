#include "helpers.h"
#include "tile.h"
#include <iostream>
using namespace std;

/**
 * @brief makeTile Creates a Tile based on the TileType
 *
 * Remember that the different TileTypes are:
 *      Wall        {{7,16}}
 *      Food        {{10,1}}
 *      Blank       {{1,4}}
 *      Pacman
 *          Up      {{3,1},{3,2},{3,1},{3,3}}
 *          Down    {{4,1},{4,2},{4,1},{4,3}}
 *          Left    {{1,1},{1,2},{1,1},{1,3}}
 *          Right   {{2,1},{2,2},{2,1},{2,3}}
 *      MrsPacman
 *          Up      {{3,5},{3,6},{3,5},{3,7}}
 *          Down    {{4,5},{4,6},{4,5},{4,7}}
 *          Left    {{1,5},{1,6},{1,5},{1,7}}
 *          Right   {{2,5},{2,6},{2,5},{2,7}}
 *      GhostR
 *          Up      {{5,1},{5,2}}
 *          Down    {{5,3},{5,4}}
 *          Left    {{5,5},{5,6}}
 *          Right   {{5,7},{5,8}}
 *      GhostP, GhostY, GhostB
 *
 * @param x X Window co-ordinate in pixels.
 * @param y Y Window co-ordinate in pixels.
 * @param t Type of the Tile to construct.
 * @param dir Direction of the Tile (Up/Down/Left/Right)
 * @return The new Tile created using the parameters.
 */
Tile makeTile(int x, int y, TileType t, Direction dir)
{
    switch(t){

		case Ready:
			return Tile (x, y, {{1,11}}, t,3,1); break;

		case GameOver:
			return Tile (x, y, {{8,12}},t,5,1); break;

		case Number:
			return Tile (x, y, {{9,2}, {9,3}, {9,4}, {9,5}, {9,6}, {9,7}, {9,8}, {9,9}, {9,10}, {9,11}}, t,1,1); break;

	    case Wall:
	        return Tile(x, y, {{7,16}},t,1,1); break;

		case GhostHome:
			return Tile (x, y, {{1,4}}, t, 1, 1);

	    case Food:
			return Tile(x, y, {{10,1}},t,1,1); break;

        case PowerFood:
            return Tile(x, y, {{14,9}, t, 1, 1});

		case Blank:
			return Tile (x, y, {{1,4}}, t,1,1);	break;

		case Pacman:
			switch (dir) {
				case Up: 
					return Tile(x, y, {{3,1}, {3,2}, {3,1}, {3,3}},t,1,1);	break;
				case Down:
					return Tile(x, y, {{4,1}, {4,2}, {4,1}, {4,3}},t,1,1);	break;
				case Left:
					return Tile (x, y, {{1,1}, {1,2}, {1,1}, {1,3}},t,1,1);	break;
				case Right:
				default:
					return Tile(x, y, {{2,1}, {2,2}, {2,1}, {2,3}},t,1,1);	break;
			}
			break;

		case MrsPacman:
			switch (dir) {
				case Up:
			    	return Tile (x, y, {{3,5},{3,6},{3,5},{3,7}},t,1,1); break;
				case Down:
					return Tile (x,y, {{4,5},{4,6},{4,5},{4,7}},t,1,1); break;
				case Left:
          			return Tile (x,y, {{1,5},{1,6},{1,5},{1,7}},t,1,1); break;
				case Right:
				default:
           			return Tile (x, y, {{2,5},{2,6},{2,5},{2,7}},t,1,1); break;
			}
			break;
	
		case GhostR:
			switch (dir) {
				case Up:
					return Tile (x, y, {{5,1}, {5,2}},t,1,1); break;
				case Down:
					return Tile (x, y, {{5,3}, {5,4}},t,1,1); break;
				case Left:
					return Tile (x, y, {{5,5}, {5,6}},t,1,1); break;
				case Right:
				default:
					return Tile (x, y, {{5,7}, {5,8}},t,1,1); break;
			}
			break;

		case GhostP:
			switch (dir) {
				case Up:
					return Tile (x, y, {{6,1}, {6,2}},t,1,1); break;
				case Down:
					return Tile (x, y, {{6,3}, {6,4}},t,1,1); break;
				case Left:
					return Tile (x, y, {{6,5}, {6,6}},t,1,1); break;
				case Right:
				default:
					return Tile (x, y, {{6,7}, {6,8}},t,1,1); break;
			}
			break;

		case GhostB:
			switch (dir) {
				case Up:
					return Tile (x, y, {{7,1}, {7,2}},t,1,1); break;
				case Down:
					return Tile (x, y, {{7,3}, {7,4}},t,1,1); break;
				case Left:
					return Tile (x, y, {{7,5}, {7,6}},t,1,1); break;
				case Right:
				default:
					return Tile (x, y, {{7,7}, {7,8}},t,1,1); break;
			}
			break;
		
		case GhostY:
			switch (dir) {
				case Up:
					return Tile (x, y, {{8,1}, {8,2}},t,1,1); break;
				case Down:
					return Tile (x, y, {{8,3}, {8,4}},t,1,1); break;
				case Left:
					return Tile (x, y, {{8,5}, {8,6}},t,1,1); break;
				case Right:
				default:
					return Tile (x, y, {{8,7}, {8,8}},t,1,1); break;
			}	
			break;

        case EatenGhost:
            switch (dir) {
                case Up:
                    return Tile (x, y, {{1, 11}}, t, 1, 1);
                    break;
                case Down:
                    return Tile (x, y, {{2, 11}}, t, 1, 1);
                    break;
                case Left:
                    return Tile (x, y, {{3, 11}}, t, 1, 1);
                    break;
                case Right:
                default:
                    return Tile (x, y, {{4, 11}}, t, 1, 1);
                    break;
            }
            break;

        case FrightenedGhost:
            return Tile (x, y, {{1, 9}, {2, 9}}, t, 1, 1);
            break;

        case LosingFrightGhost:
        default:
            return Tile (x, y, {{1, 9}, {3, 9}, {2, 9}, {4, 9}}, t, 1, 1);
            break;
	}

}

bool collision(SDL_Rect a, SDL_Rect b, int a_off, int b_off)
{

	a.w -= a_off; a.h -= a_off;
	b.w -= b_off; b.h -= b_off;


    // If A finishs above B - No Collision
	if (a.y + a.h <= b.y)
		return false;

    // If A starts below B - No Collision
	if (a.y >= b.y + b.h)
		return false;

    // If the right of A is left of B - No Collision
	if (a.x + a.w <= b.x)
		return false;

    // If the left of A is right of B - No Collision
	if (a.x >= b.x + b.w)
		return false;

//	std::cout << "A coords: " << a.x << ", " << a.y << std::endl;
	//std::cout << "B coords: " << b.x << ", " << b.y << std::endl;

    // If we get here there must be an overlap - Collision
    return true;
}