#pragma once
#include"Block.h"
class L1 :public Block
{
private:
	int block[4][4] = { {2,6,10,11},{3,5,6,7},{1,2,6,10},{5,6,7,9} };
public:
	L1();
	int* getblock() ;
	void setcolor(int R, int G, int B);
	virtual void draw(int next_x, int next_y); // ������һ������
	void operator++() override; // �����ƶ�
	void operator--() override;  // �����ƶ�
	virtual void fall(); // ����
	virtual void turn(); // ��ת
	~L1();
};
