#pragma once
#include<graphics.h>
class Color {
private:
    unsigned char R = 255, G = 255, B = 255; //Ĭ����ɫΪ��ɫ
    COLORREF RGB; 
public:
    Color(unsigned char x, unsigned char y, unsigned char z); //���������캯��
    Color(COLORREF RGB);
    ~Color(); //��������
    void setcolor(int R, int G, int B); //������ɫ�ĺ���
    COLORREF getcolor(); //��ȡ��ɫ�ĺ���
    COLORREF toRGB(); //����ɫת��ΪRGB���͵ĺ���
};
