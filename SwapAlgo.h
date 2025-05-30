#ifndef SWAP_ALGO_H
#define SWAP_ALGO_H

#include <vector>
#include "Board.h"

struct SwapStep
{
    string type;        // "row", "col", "cross"
    int param1, param2; // 具体参数
};

class SwapAlgo
{
public:
    // 交换相邻两行
    static void swapAdjacentRows(Board &board, int row);

    // 交换相邻两列
    static void swapAdjacentCols(Board &board, int col);

    // 交换十字形三个格子（中心和间隔两格的格子）
    static void swapCross(Board &board, int centerRow, int centerCol);

    // 生成随机交换步骤
    static vector<SwapStep> generateRandomMoves(Board &board, int steps);
};

#endif