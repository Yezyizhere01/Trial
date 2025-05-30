#include "SwapAlgo.h"
#include "Utility.h"

// 交换相邻两行（row和row+1）
void SwapAlgo::swapAdjacentRows(Board &board, int row)
{
    if (row >= board.getSize() - 1)
        return;
    for (int c = 0; c < board.getSize(); c++)
    {
        swap(board.get(row, c), board.get(row + 1, c));
    }
}

// 交换相邻两列（col和col+1）
void SwapAlgo::swapAdjacentCols(Board &board, int col)
{
    if (col >= board.getSize() - 1)
        return;
    for (int r = 0; r < board.getSize(); r++)
    {
        swap(board.get(r, col), board.get(r, col + 1));
    }
}

// 交换十字形：中心(r,c)、(r, c+2)、(r+2, c)三个格子
void SwapAlgo::swapCross(Board &board, int r, int c)
{
    int n = board.getSize();
    if (r + 2 >= n || c + 2 >= n)
        return;

    int center = board.get(r, c);
    int right = board.get(r, c + 2);
    int down = board.get(r + 2, c);

    board.set(r, c, right);
    board.set(r, c + 2, down);
    board.set(r + 2, c, center);
}

// 生成随机交换步骤（用于初始化打乱）
vector<SwapStep> SwapAlgo::generateRandomMoves(Board &board, int steps)
{
    vector<SwapStep> moves;
    int n = board.getSize();

    for (int i = 0; i < steps; i++)
    {
        SwapStep step;
        int type = Utility::randomInt(0, 2);

        if (type == 0)
        { // 交换行
            step.type = "row";
            step.param1 = Utility::randomInt(0, n - 2);
        }
        else if (type == 1)
        { // 交换列
            step.type = "col";
            step.param1 = Utility::randomInt(0, n - 2);
        }
        else
        { // 交换十字
            step.type = "cross";
            step.param1 = Utility::randomInt(0, n - 3);
            step.param2 = Utility::randomInt(0, n - 3);
        }

        moves.push_back(step);
    }

    return moves;
}