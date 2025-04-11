#include"Color.h"
Color::Color(unsigned char x, unsigned char y, unsigned char z) : R{ x }, G{ y }, B{ z } {} //���������캯��
Color::Color(COLORREF RGB) :RGB{ RGB } {};
Color::~Color() {} //��������

void Color::setcolor(int R, int G, int B) {
    this->R = R;
    this->G = G;
    this->B = B;
}
COLORREF Color::getcolor() {
    return RGB;
}
COLORREF Color::toRGB() {
    return RGB(R, G, B); //תΪRGB���ͣ��Ա�ʹ��easyX�⺯��
}
