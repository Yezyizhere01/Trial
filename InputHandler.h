#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <vector>
#include "Board.h"
#include "SwapAlgo.h"

class InputHandler
{
public:
    static void handleMove(Board &board, vector<SwapStep> &history);
};

#endif