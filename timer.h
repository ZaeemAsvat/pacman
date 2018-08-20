//
// Created by zaeem on 2018/01/24.
//

#ifndef PACMAN_TIMER_H
#define PACMAN_TIMER_H

#include <SDL2/SDL_quit.h>

class timer {
public:

    //Initializes variables
    timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    Uint32 getTicks();

    //Checks the status of the timer
    bool isStarted();
    bool isPaused();

private:
    //The clock time when the timer started
    Uint32 mStartTicks;

    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
};

#endif //PACMAN_TIMER_H
