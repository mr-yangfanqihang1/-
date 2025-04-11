#pragma once
#include<graphics.h>
class Color {
private:
    unsigned char R = 255, G = 255, B = 255; //默认颜色为白色
    COLORREF RGB; 
public:
    Color(unsigned char x, unsigned char y, unsigned char z); //带参数构造函数
    Color(COLORREF RGB);
    ~Color(); //析构函数
    void setcolor(int R, int G, int B); //设置颜色的函数
    COLORREF getcolor(); //获取颜色的函数
    COLORREF toRGB(); //将颜色转换为RGB类型的函数
};
