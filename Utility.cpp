#include "Utility.h"
#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

namespace Utility
{
    int randomInt(int min, int max)
    {
        static bool seeded = false;
        if (!seeded)
        {
            srand((unsigned int)time(0));
            seeded = true;
        }
        return min + rand() % (max - min + 1);
    }

    void sleep(int milliseconds)
    {
#ifdef _WIN32
        Sleep(milliseconds);
#else
        usleep(milliseconds * 1000);
#endif
    }

    string getInputString()
    {
        string s;
        getline(cin, s);
        return s;
    }

    int getInputInt()
    {
        int x;
        while (!(cin >> x))
        {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "输入无效，请输入整数：";
        }
        cin.ignore(1024, '\n');
        return x;
    }
}