#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "InputHandler.h"
#include <vector>
#include <string>

class Game
{
public:
    void run();

private:
    void printWelcome();
    void initBoard();
    int mode; // 1-练习 2-比赛
    int n;    // 棋盘大小
    Board *board;
    std::vector<SwapStep> history;
    int stepCount;
};

#endif
