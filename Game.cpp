#include "Game.h"
#include "Utility.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
using namespace std;

void Game::printWelcome()
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

void Game::initBoard()
{
    while (true)
    {
        cout << "请选择模式（1-练习模式(数字棋盘)  2-比赛模式(古诗棋盘)）：";
        mode = Utility::getInputInt();
        if (mode == 1 || mode == 2)
            break;
        cout << "请输入1或2！\n";
    }
    while (true)
    {
        cout << "请输入棋盘大小 n (6-9)：";
        n = Utility::getInputInt();
        if (n >= 6 && n <= 9)
            break;
        cout << "请输入6~9之间的整数！\n";
    }
    board = new Board(n);
    stepCount = 0;
    history.clear();
    if (mode == 1)
    {
        for (int i = 0; i < n * n; ++i)
            board->set(i / n, i % n, '1' + (i % 9));
        board->randomize();
    }
    else
    {
        ifstream fin("poem.txt");
        if (!fin)
        {
            cout << "未找到poem.txt文件，请将其放在程序同目录下。" << endl;
            exit(1);
        }
        vector<string> lines;
        string line;
        while (getline(fin, line))
        {
            if ((int)line.size() == n)
                lines.push_back(line);
        }
        if ((int)lines.size() < n)
        {
            cout << "poem.txt中不足" << n << "句" << n << "字诗句。" << endl;
            exit(1);
        }
        random_shuffle(lines.begin(), lines.end());
        string poem;
        for (int i = 0; i < n; ++i)
            poem += lines[i];
        board->setPoem(poem);
        board->randomize();
    }
}

void Game::run()
{
    printWelcome();
    initBoard();
    while (true)
    {
        cout << "\n当前棋盘：\n";
        board->print();
        cout << "步数：" << stepCount << endl;
        if (mode == 1 && board->isSolved())
        {
            cout << "恭喜你完成了排序！总步数：" << stepCount << endl;
            break;
        }
        if (mode == 2)
        {
            cout << "如已完成排序，请输入1继续，否则输入0：";
            int done = Utility::getInputInt();
            if (done == 1)
            {
                cout << "比赛模式结束！总步数：" << stepCount << endl;
                break;
            }
        }
        InputHandler::handleMove(*board, history);
        ++stepCount;
    }
    cout << "游戏结束，感谢游玩！\n";
    delete board;
}
