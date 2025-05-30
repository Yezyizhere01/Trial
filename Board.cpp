#include "Board.h"
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

Board::Board(int size) : n(size), grid(n * n)
{
    for (int i = 0; i < n * n; i++)
    {
        grid[i] = i + 1;
    }
}

void Board::randomize()
{
    random_shuffle(grid.begin(), grid.end());
}

void Board::print() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", grid[i * n + j]);
        }
        cout << endl;
    }
    cout << endl;
}

bool Board::isSolved() const
{
    for (int i = 0; i < n * n; i++)
    {
        if (grid[i] != i + 1)
            return false;
    }
    return true;
}

int Board::get(int r, int c) const
{
    return grid[r * n + c];
}

void Board::set(int r, int c, int val)
{
    grid[r * n + c] = val;
}

// 交换相邻两行
bool Board::swapRows(int row1, int row2)
{
    if (abs(row1 - row2) != 1 || row1 < 0 || row2 < 0 || row1 >= n || row2 >= n)
        return false;
    for (int j = 0; j < n; j++)
        swap(grid[row1 * n + j], grid[row2 * n + j]);
    return true;
}

// 交换相邻两列
bool Board::swapCols(int col1, int col2)
{
    if (abs(col1 - col2) != 1 || col1 < 0 || col2 < 0 || col1 >= n || col2 >= n)
        return false;
    for (int i = 0; i < n; i++)
        swap(grid[i * n + col1], grid[i * n + col2]);
    return true;
}

// 十字交换：以两个间隔两格的数字为中心，交换十字
bool Board::crossSwap(int r1, int c1, int r2, int c2)
{
    // 必须间隔两格
    if (!(abs(r1 - r2) == 2 && c1 == c2) && !(abs(c1 - c2) == 2 && r1 == r2))
        return false;
    if (r1 < 0 || r1 >= n || r2 < 0 || r2 >= n || c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
        return false;
    // 交换十字上的5个点
    if (r1 == r2) // 同行，列间隔2
    {
        int row = r1;
        int colA = c1, colB = c2;
        swap(grid[row * n + colA], grid[row * n + colB]);
        if (row - 1 >= 0 && row + 1 < n)
        {
            swap(grid[(row - 1) * n + colA], grid[(row - 1) * n + colB]);
            swap(grid[(row + 1) * n + colA], grid[(row + 1) * n + colB]);
        }
    }
    else // 同列，行间隔2
    {
        int col = c1;
        int rowA = r1, rowB = r2;
        swap(grid[rowA * n + col], grid[rowB * n + col]);
        if (col - 1 >= 0 && col + 1 < n)
        {
            swap(grid[rowA * n + (col - 1)], grid[rowB * n + (col - 1)]);
            swap(grid[rowA * n + (col + 1)], grid[rowB * n + (col + 1)]);
        }
    }
    return true;
}