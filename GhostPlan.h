//
// Created by User on 2018/08/09.
//

#ifndef PACMAN_GHOSTPLAN_H
#define PACMAN_GHOSTPLAN_H


#include <vector>
#include "GhostScatterPeriod.h"

class GhostPlan {

public:

    GhostPlan ();

    static void addScatter (GhostScatterPeriod scatterPeriod);
    static void addScatter (Uint32 start, Uint32 duration);
    static bool hasPendingScztterPeriod();
    static GhostScatterPeriod getCurrScatter();
    static void goToNextScatterPeriod();
    static void resetScatterPeriods();
    static void clearScatterPeriods();

    static void setFrightenedDuration (Uint32 duration);
    static Uint32 getFrightenedDuration();
    static void setLosingFrightduration (Uint32 duration);
    static Uint32 getLosingFrightduration();

    void setInitialInactiveDuration (Uint32 duration);
    Uint32 getInitialInactiveDuration();

    void setInactiveOnceBittenDuration (Uint32 duration);
    Uint32 getInactiveOnceBittenDuration();

private:
    static std::vector<GhostScatterPeriod> scatterPeriods;
    static Uint32 frightened_duration, losingFright_duration;
    Uint32 inactive_before_start_duration = 0, inactive_once_eatsm_duration = 0;

    static int curr_scatter_index;

};
#endif //PACMAN_GHOSTPLAN_H