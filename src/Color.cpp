#include"Color.h"
Color::Color(unsigned char x, unsigned char y, unsigned char z) : R{ x }, G{ y }, B{ z } {} //带参数构造函数
Color::Color(COLORREF RGB) :RGB{ RGB } {};
Color::~Color() {} //析构函数

void Color::setcolor(int R, int G, int B) {
    this->R = R;
    this->G = G;
    this->B = B;
}
COLORREF Color::getcolor() {
    return RGB;
}
COLORREF Color::toRGB() {
    return RGB(R, G, B); //转为RGB类型，以便使用easyX库函数
}
