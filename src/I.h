#pragma once
#include"Block.h"
class I :public Block
{
private:
    int block[4][4] = { {2,6,10,14},{1,2,3,4},{2,6,10,14},{1,2,3,4} };  //I�ͷ����������״
public:
    I();  //���캯�������÷�����ɫ
    int* getblock();  //��ȡ��ǰ��״�ķ���
    void setcolor(int R, int G, int B);
    virtual void draw(int next_x, int next_y); // ������һ������
    void operator++() override; // �����ƶ�
    void operator--() override;  // �����ƶ�
    virtual void fall(); // ����
    virtual void turn(); // ��ת
    ~I();
};