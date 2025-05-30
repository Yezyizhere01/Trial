#include "InputHandler.h"
#include "Utility.h"
#include <iostream>

void InputHandler::handleMove(Board &board, vector<SwapStep> &history)
{
    cout << "请选择操作（1-行交换，2-列交换，3-十字交换）：";
    int choice = Utility::getInputInt();
    SwapStep step;

    switch (choice)
    {
    case 1:
    { // 交换相邻行
        cout << "输入行号（0-" << board.getSize() - 2 << "）：";
        int row = Utility::getInputInt();
        SwapAlgo::swapAdjacentRows(board, row);
        step = {"row", row, 0};
        break;
    }
    case 2:
    { // 交换相邻列
        cout << "输入列号（0-" << board.getSize() - 2 << "）：";
        int col = Utility::getInputInt();
        SwapAlgo::swapAdjacentCols(board, col);
        step = {"col", col, 0};
        break;
    }
    case 3:
    { // 交换十字
        cout << "输入中心行号（0-" << board.getSize() - 3 << "）：";
        int r = Utility::getInputInt();
        cout << "输入中心列号（0-" << board.getSize() - 3 << "）：";
        int c = Utility::getInputInt();
        SwapAlgo::swapCross(board, r, c);
        step = {"cross", r, c};
        break;
    }
    default:
        cout << "无效选择！" << endl;
        return;
    }

    history.push_back(step);
}