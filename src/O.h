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
    virtual void draw(int next_x, int next_y) ; // ������һ������
    void operator++() override; // �����ƶ�
    void operator--() override;  // �����ƶ�
    virtual void fall(); // ����
    virtual void turn(); // ��ת
    ~O() ;
};



