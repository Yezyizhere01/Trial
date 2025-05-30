#include <iostream>
#include <vector>
#include "include/Board.h"
#include "include/SwapAlgo.h"
#include "include/InputHandler.h"
#include "include/Utility.h"

using namespace Utility;

int main()
{
    srand(time(0));
    cout << "请输入棋盘大小（n≥3）：";
    int n = getInputInt();
    Board board(n);

    // 生成随机打乱步骤
    vector<SwapStep> initMoves = SwapAlgo::generateRandomMoves(board, 20);
    for (auto &move : initMoves)
    {
        if (move.type == "row")
            SwapAlgo::swapAdjacentRows(board, move.param1);
        else if (move.type == "col")
            SwapAlgo::swapAdjacentCols(board, move.param1);
        else if (move.type == "cross")
            SwapAlgo::swapCross(board, move.param1, move.param2);
    }

    vector<SwapStep> history;

    while (!board.isSolved())
    {
        system("cls"); // 清屏
        board.print();
        cout << "当前步骤数：" << history.size() << endl;
        InputHandler::handleMove(board, history);
        sleep(300);
    }

    system("cls");
    board.print();
    cout << "恭喜完成！共使用" << history.size() << "步" << endl;
    return 0;
}