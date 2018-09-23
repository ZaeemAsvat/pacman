#include <iostream>
#include <thread>
#include <chrono>

#include "window.h"
#include "texture.h"
#include "tile.h"
#include "helpers.h"
#include "character.h"
#include "world.h"
#include "loadLevelHelpers.h"

using namespace std;

void displayGameOver (World MyWorld, Texture &MyTextures, int frame) {
    MyWorld.render(&MyTextures, frame);
    if (frame % 10 != 0) {
        Tile game_over = makeTile(MyWorld.cols/2.7*MyTextures.tileWidth(), MyWorld.rows/2.7*MyTextures.tileHeight(), GameOver);
        game_over.render(&MyTextures, frame);
    }
}

int main()
{
    // SpriteSheet Filename
    string spriteFilename = "sprites.png"; // Leave this line

    // Setup and Load Texture object here
    Texture MyTextures;
    MyTextures.loadFile (spriteFilename, 20, 20);
    Tile::tileWidth = 20; Tile::tileHeight = 20;

    loadLevelHelpers levelHelpers;

    // loading only level one for now
    World MyWorld = levelHelpers.loadLevelOne("maze2.txt", MyTextures.tileWidth(), MyTextures.tileHeight());
    int num_lives = 3;
    bool pacman_is_out_of_lives = false;

    int frame = 0;
    bool running = true;

    MyWorld.ghost_timer.start();

    while(running){
        SDL_Event e;
        while (SDL_PollEvent (&e)) {

            if (e.type == SDL_QUIT)
                running = false;

            MyTextures.handle_event(e, MyWorld.rows, MyWorld.cols);
            MyWorld.myPacman.handle_event(e);
        }


        //set renderer draw colour to black
        SDL_SetRenderDrawColor (MyTextures.myWin.sdlRenderer, 0, 0, 0, 0xFF);

        //clear the screen
        SDL_RenderClear (MyTextures.myWin.sdlRenderer);

        if (MyWorld.ready) {
            MyWorld.UpdateWorld();
            MyWorld.render(&MyTextures, frame);
        } else {

            if (pacman_is_out_of_lives)
                displayGameOver(MyWorld, MyTextures, frame);
            else {

                MyWorld.ghost_timer.pause();

                if (MyWorld.myPacman.eaten) {
                    --num_lives;
                    if (num_lives <= 0) {
                        pacman_is_out_of_lives = true;
                        displayGameOver(MyWorld, MyTextures, frame);
                    } else {
                        MyWorld.resetCharacterPositions();
                        MyWorld.ghost_timer.unpause();
                    }
                }
            }

        }

        //update screen
        SDL_RenderPresent (MyTextures.myWin.sdlRenderer);

        //delay a bit before next render
        this_thread::sleep_for(chrono::milliseconds(50));

        //go to next frame
        ++frame;

        // Handle any SDL Events
        // Such as resize, clicking the close button,
        //  and process and key press events.

        // Update the Game State Information

        // Draw the current state to the screen.
    }

    return 0;
}