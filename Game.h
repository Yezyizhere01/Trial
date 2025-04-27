/*
*********************
*                   *
* Game.h            *
*                   *
*********************
*/

#ifndef Game_H
#define Game_H

#include "PrintingPlate.h"

class Game
{
    private:
        PrintingPlate plate;
    public:
        void startGame();
        void endGame();
        void playerInput();
};

#endif