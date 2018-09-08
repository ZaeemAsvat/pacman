#ifndef PACMAN_H
#define PACMAN_H

#include "character.h"
#include "helpers.h"

class pacman : public Character {

public:

    pacman (int myX, int myY, int spd);

	void handle_event(SDL_Event &e);

	Direction prevDir = NoDirection;
	Direction pendingDir = NoDirection;
	bool movePending = false;
	bool eaten = false;

};

#endif
