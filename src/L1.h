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
	virtual void draw(int next_x, int next_y); // 绘制下一个方块
	void operator++() override; // 向右移动
	void operator--() override;  // 向左移动
	virtual void fall(); // 下落
	virtual void turn(); // 旋转
	~L1();
};
