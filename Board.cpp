#include "Board.h"
#include <algorithm>
#include <cstdlib>

Board::Board(int size) : n(size)
{
    grid.resize(n, vector<int>(n));
    for (int i = 0; i < n * n; i++)
    {
        grid[i / n][i % n] = i + 1;
    }
}

void Board::randomize()
{
    vector<int> values;
    for (int i = 0; i < n * n; i++)
        values.push_back(i + 1);
    random_shuffle(values.begin(), values.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = values[i * n + j];
        }
    }
}

void Board::print() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", grid[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

bool Board::isSolved() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != i * n + j + 1)
                return false;
        }
    }
    return true;
}

int Board::get(int r, int c) const
{
    return grid[r][c];
}

void Board::set(int r, int c, int val)
{
    grid[r][c] = val;
}