#ifndef UTILITY_H
#define UTILITY_H

#include <cstdlib>
#include <ctime>

namespace Utility
{
    int randomInt(int min, int max);
    void sleep(int milliseconds);
    string getInputString();
    int getInputInt();
}

#endif