#include "SwapAlgo.h"
#include "Utility.h"

// 交换相邻两行（row和row+1）
void SwapAlgo::swapAdjacentRows(Board &board, int row)
{
    if (row >= board.getSize() - 1)
        return;
    for (int c = 0; c < board.getSize(); c++)
    {
        int temp = board.get(row, c);
        board.set(row, c, board.get(row + 1, c));
        board.set(row + 1, c, temp);
    }
}

// 交换相邻两列（col和col+1）
void SwapAlgo::swapAdjacentCols(Board &board, int col)
{
    if (col >= board.getSize() - 1)
        return;
    for (int r = 0; r < board.getSize(); r++)
    {
        int temp = board.get(r, col);
        board.set(r, col, board.get(r, col + 1));
        board.set(r, col + 1, temp);
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
std::vector<SwapStep> SwapAlgo::generateRandomMoves(Board &board, int steps)
{
    std::vector<SwapStep> moves;
    int n = board.getSize();

    for (int i = 0; i < steps; i++)
    {
        SwapStep step;
        int type = Utility::randomInt(0, 2);

        if (type == 0)
        { // 交换行
            step.type = "row";
            step.a = Utility::randomInt(0, n - 2);
            step.b = step.a + 1;
        }
        else if (type == 1)
        { // 交换列
            step.type = "col";
            step.a = Utility::randomInt(0, n - 2);
            step.b = step.a + 1;
        }
        else
        { // 交换十字
            step.type = "cross";
            step.a = Utility::randomInt(0, n - 3);
            step.b = Utility::randomInt(0, n - 3);
        }

        moves.push_back(step);
    }

    return moves;
}

// 行交换
bool SwapAlgo::swapRows(Board &board, int row1, int row2)
{
    return board.swapRows(row1, row2);
}

// 列交换
bool SwapAlgo::swapCols(Board &board, int col1, int col2)
{
    return board.swapCols(col1, col2);
}

// 十字交换
bool SwapAlgo::crossSwap(Board &board, int r1, int c1, int r2, int c2)
{
    return board.crossSwap(r1, c1, r2, c2);
}