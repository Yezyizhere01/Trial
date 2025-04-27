/*
*********************
*                   *
* PrintingPlate.h   *
*                   *
*********************
*/

#ifndef PrintingPlate_H
#define PrintingPlate_H

#include "CharactarBlock.h"

class PrintingPlate
{
    private:
        CharactarBlock block;
        int targetBlock;
        int steps;
        int time;
    public:
        void initPlate();
        void displayPlate();
        bool checkTarget();
        void moveBlock(CharactarBlock &b);
};

#endif