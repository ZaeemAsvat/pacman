//
// Created by User on 2018/08/03.
//


#include "GhostPlan.h"
#include "world.h"

World loadLevelOne(std::string maze_file, int tileWidth, int tileHeight) {

    World world = World (maze_file, tileWidth, tileHeight);

    // clear possible existing scatter data and set the data for this level
    GhostPlan::clearScatterPeriods();
    GhostPlan::addScatter(20000, 7000);
    GhostPlan::addScatter(27000, 7000);
    GhostPlan::addScatter(54000, 5000);
    GhostPlan::addScatter(79000, 5000);

    // set various durations for this level
    GhostPlan::setFrightenedDuration(8000);
    GhostPlan::setLosingFrightduration(3000);
    world.Red.getGhostPlan().setInitialInactiveDuration(0);
    world.Red.getGhostPlan().setInactiveOnceBittenDuration(1000);

    // set Scatter Rectangle for Red (hard-coded for now until i come up with a better way)
    world.Red.setScatterRec (mazeIndex(1,1), mazeIndex (1,4), mazeIndex(4, 1), mazeIndex (4, 4));

    // set ghost home indices (again, hard-coded. Ugh)
    ghost::setsHome(mazeIndex(9, 9), mazeIndex(10,9), mazeIndex(10, 8), mazeIndex(10, 10));

    return world;
}