#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
using namespace std;

class Board
{
private:
    int n;
    std::vector<char> grid; // 改为char类型，支持诗句

public:
    Board(int size);
    void randomize();      // 随机打乱棋盘
    void print() const;    // 打印棋盘
    bool isSolved() const; // 检查是否完成排序
    char get(int r, int c) const;
    void set(int r, int c, char val);
    int getSize() const { return n; }
    void setPoem(const std::string &poem); // 新增：将诗句填入棋盘
    // 新增三种交换操作
    bool swapRows(int row1, int row2);              // 交换相邻两行
    bool swapCols(int col1, int col2);              // 交换相邻两列
    bool crossSwap(int r1, int c1, int r2, int c2); // 十字交换
};

#endif