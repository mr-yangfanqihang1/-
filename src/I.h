#pragma once
#include"Block.h"
class I :public Block
{
private:
    int block[4][4] = { {2,6,10,14},{1,2,3,4},{2,6,10,14},{1,2,3,4} };  //I型方块的四种形状
public:
    I();  //构造函数，设置方块颜色
    int* getblock();  //获取当前形状的方块
    void setcolor(int R, int G, int B);
    virtual void draw(int next_x, int next_y); // 绘制下一个方块
    void operator++() override; // 向右移动
    void operator--() override;  // 向左移动
    virtual void fall(); // 下落
    virtual void turn(); // 旋转
    ~I();
};