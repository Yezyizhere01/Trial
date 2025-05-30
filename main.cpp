#include "Board.h"
#include "SwapAlgo.h"
#include "InputHandler.h"
#include "Utility.h"
#include <iostream>
#include <vector>
using namespace std;

void printWelcome()
{
    cout << "==============================\n";
    cout << "  最强大脑小游戏：活字飞花  \n";
    cout << "==============================\n";
    cout << "规则：\n";
    cout << "在 n x n 棋盘上有 1~n^2 的数字，通过如下三种操作将其按顺序排列：\n";
    cout << "1. 交换相邻两行\n";
    cout << "2. 交换相邻两列\n";
    cout << "3. 以两个间隔两格的数字为中心的十字交换\n";
    cout << "支持命令行模式输入：swap row 1 2 / swap col 1 2 / cross 1 2 3 2\n";
    cout << "==============================\n";
}

int main()
{
    printWelcome();
    int n;
    while (true)
    {
        cout << "请输入棋盘大小 n (6-9)：";
        n = Utility::getInputInt();
        if (n >= 6 && n <= 9)
            break;
        cout << "请输入6~9之间的整数！\n";
    }
    Board board(n);
    board.randomize();
    vector<SwapStep> history;
    int stepCount = 0;
    while (true)
    {
        cout << "\n当前棋盘：\n";
        board.print();
        cout << "步数：" << stepCount << endl;
        if (board.isSolved())
        {
            cout << "恭喜你完成了排序！总步数：" << stepCount << endl;
            break;
        }
        InputHandler::handleMove(board, history);
        ++stepCount;
    }
    cout << "游戏结束，感谢游玩！\n";
    return 0;
}