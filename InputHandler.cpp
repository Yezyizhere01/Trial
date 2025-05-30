#include "InputHandler.h"
#include "Utility.h"
#include "SwapAlgo.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 辅助结构体用于记录操作历史
struct SwapStep
{
    string type;
    int a, b;
};

// 辅助函数：分割字符串
static vector<string> split(const string &s)
{
    vector<string> tokens;
    istringstream iss(s);
    string token;
    while (iss >> token)
        tokens.push_back(token);
    return tokens;
}

// 交互式操作
void InputHandler::handleMove(Board &board, vector<SwapStep> &history)
{
    cout << "请选择操作（1-行交换，2-列交换，3-十字交换，4-命令行模式）：";
    int choice = Utility::getInputInt();
    SwapStep step;
    if (choice == 4)
    {
        cout << "请输入操作指令（如 swap row 1 2 / swap col 1 2 / cross 1 2 3 2）：";
        string input = Utility::getInputString();
        string message;
        if (InputHandler::handleCommand(board, input, message))
        {
            cout << message << endl;
            step = {"cmd", 0, 0};
            history.push_back(step);
        }
        else
        {
            cout << message << endl;
        }
        return;
    }
    switch (choice)
    {
    case 1:
    { // 交换相邻行
        cout << "输入行号（0-" << board.getSize() - 2 << "）：";
        int row1 = Utility::getInputInt();
        int row2 = row1 + 1;
        if (SwapAlgo::swapRows(board, row1, row2))
        {
            cout << "行交换成功。" << endl;
            step = {"row", row1, row2};
            history.push_back(step);
        }
        else
        {
            cout << "行交换参数不合法。" << endl;
        }
        break;
    }
    case 2:
    { // 交换相邻列
        cout << "输入列号（0-" << board.getSize() - 2 << "）：";
        int col1 = Utility::getInputInt();
        int col2 = col1 + 1;
        if (SwapAlgo::swapCols(board, col1, col2))
        {
            cout << "列交换成功。" << endl;
            step = {"col", col1, col2};
            history.push_back(step);
        }
        else
        {
            cout << "列交换参数不合法。" << endl;
        }
        break;
    }
    case 3:
    { // 交换十字
        cout << "输入第一个中心行号：";
        int r1 = Utility::getInputInt();
        cout << "输入第一个中心列号：";
        int c1 = Utility::getInputInt();
        cout << "输入第二个中心行号：";
        int r2 = Utility::getInputInt();
        cout << "输入第二个中心列号：";
        int c2 = Utility::getInputInt();
        if (SwapAlgo::crossSwap(board, r1, c1, r2, c2))
        {
            cout << "十字交换成功。" << endl;
            step = {"cross", r1, c1};
            history.push_back(step);
        }
        else
        {
            cout << "十字交换参数不合法。" << endl;
        }
        break;
    }
    default:
        cout << "无效选择！" << endl;
        return;
    }
}

// 命令行模式解析与执行
bool InputHandler::handleCommand(Board &board, const string &input, string &message)
{
    auto tokens = split(input);
    if (tokens.empty())
    {
        message = "请输入操作指令。";
        return false;
    }
    if (tokens[0] == "swap")
    {
        if (tokens.size() == 4 && tokens[1] == "row")
        {
            int r1 = stoi(tokens[2]), r2 = stoi(tokens[3]);
            if (SwapAlgo::swapRows(board, r1, r2))
            {
                message = "行交换成功。";
                return true;
            }
            else
            {
                message = "行交换参数不合法。";
                return false;
            }
        }
        if (tokens.size() == 4 && tokens[1] == "col")
        {
            int c1 = stoi(tokens[2]), c2 = stoi(tokens[3]);
            if (SwapAlgo::swapCols(board, c1, c2))
            {
                message = "列交换成功。";
                return true;
            }
            else
            {
                message = "列交换参数不合法。";
                return false;
            }
        }
    }
    if (tokens[0] == "cross" && tokens.size() == 5)
    {
        int r1 = stoi(tokens[1]), c1 = stoi(tokens[2]), r2 = stoi(tokens[3]), c2 = stoi(tokens[4]);
        if (SwapAlgo::crossSwap(board, r1, c1, r2, c2))
        {
            message = "十字交换成功。";
            return true;
        }
        else
        {
            message = "十字交换参数不合法。";
            return false;
        }
    }
    message = "未知指令。";
    return false;
}