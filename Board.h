#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
using namespace std;

class Board
{
private:
    int n;
    vector<int> grid; // 一维存储

public:
    Board(int size);
    void randomize();      // 随机打乱棋盘
    void print() const;    // 打印棋盘
    bool isSolved() const; // 检查是否完成排序
    int get(int r, int c) const;
    void set(int r, int c, int val);
    int getSize() const { return n; }
    // 新增三种交换操作
    bool swapRows(int row1, int row2);              // 交换相邻两行
    bool swapCols(int col1, int col2);              // 交换相邻两列
    bool crossSwap(int r1, int c1, int r2, int c2); // 十字交换
};

#endif