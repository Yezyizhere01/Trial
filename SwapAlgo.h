#ifndef SWAP_ALGO_H
#define SWAP_ALGO_H

#include <vector>
#include "Board.h"
#include "InputHandler.h" // 只引用SwapStep结构体

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
    static std::vector<SwapStep> generateRandomMoves(Board &board, int steps);

    // 封装三种交换操作，返回操作是否成功
    static bool swapRows(Board &board, int row1, int row2);
    static bool swapCols(Board &board, int col1, int col2);
    static bool crossSwap(Board &board, int r1, int c1, int r2, int c2);
};

#endif