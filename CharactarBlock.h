/*
*********************
*                   *
* CharactarBlock.h  *
*                   *
*********************
*/

#ifndef CharactarBlock_H
#define CharactarBlock_H

class CharactarBlock
{
    private:
        int x,y;
        char content;
        int direction;
    public:
        void move();
        void rotate();
};

#endif