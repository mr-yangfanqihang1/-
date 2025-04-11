#pragma once
#include <graphics.h>
#include"Color.h"
extern COLORREF colors[7];
class Block {
protected:
    static int num;
    Color* c=new Color(colors[num%7]);//较为巧妙的实现每个块一个颜色
public:  
    static int getnum();
    COLORREF getcolor(); // 获取颜色
    Block() = default; // 默认构造函数
    virtual void draw(int next_x,int next_y) = 0; // 绘制方块
    virtual void operator++() {}
    virtual void operator--() {}
    virtual void fall()=0; // 下落
    virtual void turn()=0; // 旋转
    virtual int* getblock()=0;//获取数组
};