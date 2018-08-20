//
// Created by User on 2018/08/09.
//

#include "GhostScatterPeriod.h"

GhostScatterPeriod::GhostScatterPeriod(Uint32 s, Uint32 d) {
    start = s;
    duration = d;
}

void GhostScatterPeriod::setStart(Uint32 s) {
    start = s;
}

Uint32 GhostScatterPeriod::getStart() {
    return start;
}

void GhostScatterPeriod::setDurztion(Uint32 d) {
    duration = d;
}

Uint32 GhostScatterPeriod::getDuration() {
    return duration;
}