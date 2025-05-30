#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <vector>
#include "Board.h"
#include <string>

struct SwapStep
{
    std::string type;
    int a, b;
};

class InputHandler
{
public:
    // 交互式操作，history用于记录操作历史
    static void handleMove(Board &board, std::vector<SwapStep> &history);
    // 命令行模式解析与执行
    static bool handleCommand(Board &board, const std::string &input, std::string &message);
};

#endif