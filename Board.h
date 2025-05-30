#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
using namespace std;

class Board
{
private:
    int n;
    vector<vector<int>> grid;

public:
    Board(int size);
    void randomize();      // 随机打乱棋盘
    void print() const;    // 打印棋盘
    bool isSolved() const; // 检查是否完成排序
    int get(int r, int c) const;
    void set(int r, int c, int val);
    int getSize() const { return n; }
};

#endif