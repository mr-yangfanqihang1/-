#pragma once
#include"Block.h"
class L2 :public Block
{
private:
	int block[4][4] = { {2,6,10,9},{11,5,6,7},{3,2,6,10},{5,6,7,1} };
public:
	L2() ; 
	int* getblock() ;
	void setcolor(int R, int G, int B);
	virtual void draw(int next_x, int next_y) ; // ������һ������
	void operator++() override; // �����ƶ�
	void operator--() override;  // �����ƶ�
	virtual void fall(); // ����
	virtual void turn(); // ��ת
	~L2();
};

