#include "Utility.h"
#include <windows.h> // for Sleep()

int Utility::randomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void Utility::sleep(int milliseconds)
{
    Sleep(milliseconds);
}

string Utility::getInputString()
{
    string str;
    getline(cin, str);
    return str;
}

int Utility::getInputInt()
{
    int num;
    cin >> num;
    cin.ignore(); // 清除缓冲区
    return num;
}