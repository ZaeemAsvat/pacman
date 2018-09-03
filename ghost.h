#ifndef GHOST_H
#define GHOST_H

#include <queue>
#include <array>
#include "character.h"
#include "helpers.h"
#include "tile.h"
#include "mazeIndex.h"
#include "GhostPlan.h"

enum ghost_mode {Chase, Scatter};

enum ghost_character {red, blue, pink, yellow};

enum ghostHomeIndices {HomeUpIndex, HomeDownIndex, HomeLeftIndex, HomeRightIndex, HomeTotalIndices};

class ghost : public Character {

public:

    ghost (int myX, int myY, TileType t, int spd);

    ghost();

	static void setMode (ghost_mode m);
	static ghost_mode getMode();

	void bfs (std::vector<std::vector<Tile>> maze);
	void UpdateDirection();

    bool isActive();
    void setActive (bool a);

    static void setsHome (mazeIndex up, mazeIndex down, mazeIndex left, mazeIndex right);

    static std::array<mazeIndex, 4> getHome();

    void setTarget (mazeIndex target);

    virtual void assignTilePos (SDL_Rect rec) override;
    virtual void render(Texture *t, int frame) override;

	void setGhostPlan (GhostPlan p);
	GhostPlan getGhostPlan ();

	void setScatterPoints (mazeIndex index1, mazeIndex index2);
	std::pair<mazeIndex> getScatterPoints();
	mazeIndex getCurrScatterTarget();
	void setCurrScatterTarget (int index);
	int getCurrScatterTargetIndex();

	void setEaten (bool e);
	bool hasBeenEaten();

	void setFrightened (bool frightened);
	bool isFrightened ();
	void setLosingFright (bool losing_fright);
	bool isLosingFright();

    Tile frightenedTile;
    Tile losingFrightTile;

    Tile eatenUTile;
    Tile eatenDTile;
    Tile eatenLTile;
    Tile eatenRTile;



protected:
    // whether in house or not
    bool active = false;

    bool eaten = false;

    bool frightened = false, losing_fright = false;

    // Tile positions of ghost's home
    static std::array<mazeIndex, HomeTotalIndices> homeIndices;

	static ghost_mode mode;
	std::vector<std::vector<bool>> ghostPath;

    bool isWithinRange (mazeIndex i, int max_width, int max_height);
    bool isAValidMove (mazeIndex i, std::vector<std::vector<Tile> > maze);
	int round (int x, int n);

    mazeIndex TargetIndex;

    std::pair<mazeIndex> scatterPoints;
    int currScatterTargetIndex = -1;

    GhostPlan plan;
};

#endif