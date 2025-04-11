#pragma once
#include <graphics.h>
#include"Color.h"
extern COLORREF colors[7];
class Block {
protected:
    static int num;
    Color* c=new Color(colors[num%7]);//��Ϊ�����ʵ��ÿ����һ����ɫ
public:  
    static int getnum();
    COLORREF getcolor(); // ��ȡ��ɫ
    Block() = default; // Ĭ�Ϲ��캯��
    virtual void draw(int next_x,int next_y) = 0; // ���Ʒ���
    virtual void operator++() {}
    virtual void operator--() {}
    virtual void fall()=0; // ����
    virtual void turn()=0; // ��ת
    virtual int* getblock()=0;//��ȡ����
};