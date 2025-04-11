#pragma once
#include"Block.h"
class O :public Block
{
private:
    int block[4][4] = { {1,2,5,6},{1,2,5,6},{1,2,5,6},{1,2,5,6} };
public:
    O();
    int* getblock() ;
    void setcolor(int R, int G, int B);
    virtual void draw(int next_x, int next_y) ; // 绘制下一个方块
    void operator++() override; // 向右移动
    void operator--() override;  // 向左移动
    virtual void fall(); // 下落
    virtual void turn(); // 旋转
    ~O() ;
};



