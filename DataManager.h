/*
*********************
*                   *
*   DataManager.h   *
*                   *
*********************
*/

#ifndef DataManager_H
#define DataManager_H

#include <vector>
#include <iostream>

class DataManager
{
    private:
        std::vector<int> plateData;
        std::vector<int> targetData;
    public:
        void loadPlateData(const std::string &filename);
        void saveGameData(const std::string &filename);
};

#endif