//
// Created by User on 2018/08/09.
//

#ifndef PACMAN_GHOSTSCATTERPERIOD_H
#define PACMAN_GHOSTSCATTERPERIOD_H

#include <SDL2/SDL_quit.h>

class GhostScatterPeriod {

public:

    GhostScatterPeriod (Uint32 s, Uint32 d);

    void setStart (Uint32 s);
    Uint32 getStart();

    void setDurztion (Uint32 d);
    Uint32 getDuration();

private:
    Uint32 start, duration;
};


#endif //PACMAN_GHOSTSCATTERPERIOD_H
