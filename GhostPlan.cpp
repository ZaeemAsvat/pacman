//
// Created by User on 2018/08/09.
//

#include <stdexcept>
#include "GhostPlan.h"

int GhostPlan::curr_scatter_index = -1;
Uint32 GhostPlan::frightened_duration = 0;
Uint32 GhostPlan::losingFright_duration = 0;
std::vector<GhostScatterPeriod> GhostPlan::scatterPeriods;

GhostPlan::GhostPlan() {
    GhostPlan::curr_scatter_index = -1;
    GhostPlan::frightened_duration = 0;
    GhostPlan::losingFright_duration = 0;
}

void GhostPlan::addScatter(GhostScatterPeriod scatterPeriod) {
    scatterPeriods.push_back(scatterPeriod);

    if (curr_scatter_index == -1)
        curr_scatter_index = 0;
}

void GhostPlan::addScatter(Uint32 start, Uint32 duration) {
    scatterPeriods.push_back(GhostScatterPeriod (start, duration));

    if (curr_scatter_index == -1)
        curr_scatter_index = 0;
}

GhostScatterPeriod GhostPlan::getCurrScatter() {
    if (curr_scatter_index >= 0 && curr_scatter_index < scatterPeriods.size())
        return scatterPeriods[curr_scatter_index];
    else
        throw std::runtime_error ("No more scatter periods available");
}

bool GhostPlan::hasPendingScztterPeriod() {
    return curr_scatter_index >= 0 && curr_scatter_index < scatterPeriods.size();
}

void GhostPlan::clearScatterPeriods() {
    scatterPeriods.clear();
}

void GhostPlan::goToNextScatterPeriod() {
    ++curr_scatter_index;
}

void GhostPlan::resetScatterPeriods() {
    if (curr_scatter_index > 0)
        curr_scatter_index = 0;
}

void GhostPlan::setFrightenedDuration(Uint32 duration) {
    frightened_duration = duration;
}

Uint32 GhostPlan::getFrightenedDuration() {
    return frightened_duration;
}

void GhostPlan::setLosingFrightduration(Uint32 duration) {
    losingFright_duration = duration;
}

Uint32 GhostPlan::getLosingFrightduration() {
    return losingFright_duration;
}

void GhostPlan::setInitialInactiveDuration(Uint32 duration) {
    inactive_before_start_duration = duration;
}

Uint32 GhostPlan::getInitialInactiveDuration() {
    return inactive_before_start_duration;
}

void GhostPlan::setInactiveOnceBittenDuration(Uint32 duration) {
    inactive_once_eatsm_duration = duration;
}

Uint32 GhostPlan::getInactiveOnceBittenDuration() {
    return inactive_once_eatsm_duration;
}