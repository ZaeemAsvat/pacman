cmake_minimum_required(VERSION 3.12)

project(pacman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lSDL2 -lSDL_image")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp window.h window.cpp
        world.h world.cpp
        tile.h tile.cpp
        texture.h texture.cpp
        pacman.h pacman.cpp
        ghost.h ghost.cpp
        helpers.h helpers.cpp
        character.h character.cpp
        maze2.txt
        sprites.png
        timer.h timer.cpp BlueGhost.cpp BlueGhost.h
        RedGhost.cpp RedGhost.h
        mazeIndex.h mazeIndex.cpp
        LoadLevelHelpers.cpp
        GhostPlan.h GhostPlan.cpp
        GhostScatterPeriod.h GhostScatterPeriod.cpp)


configure_file(sprites.png sprites.png COPYONLY)
configure_file(maze2.txt maze2.txt COPYONLY)

add_executable(pacman ${SOURCE_FILES})
target_link_libraries(pacman SDL2main SDL2 SDL_image)