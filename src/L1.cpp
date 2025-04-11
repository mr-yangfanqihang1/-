#include "L1.h"
#include"public.h"
extern int x, y,shape,nowcolor;
extern COLORREF colors[7];
extern bool land;
L1::L1() { num++; }
int* L1::getblock() { return block[shape]; };
void L1::setcolor(int R, int G, int B) {
	c->setcolor(R, G, B);
}
void L1::draw(int next_x, int next_y) {
	int temp_x, temp_y;
	for (int i = 0; i < 4; i++) {
		temp_x = next_x + 72 * (this->getblock()[i] % 4 - 1);   //һ��Ҫע��ǡ�������������Ȼdebug�ǳ�ʹ��
		temp_y = next_y + 72 * (this->getblock()[i] / 4);
		if (this->getblock()[i] % 4 == 0) { temp_x += 72 * 4; temp_y -= 72; }
		Drawblock(temp_x, temp_y, c->getcolor());
	}
};
void L1::operator++() {
	x += 72;
	if (check(this->getblock())) {
		return;
	}
	else {
		x -= 72;
	}
}
void L1::operator--() {
	x -= 72;
	if (check(this->getblock())) {
		return;
	}
	else {
		x += 72;
	}
}
void L1::fall() {
	y += 72;
	if (check(this->getblock())) {
		return;
	}
	else {
		y -= 72;
		land = !land;
	}
}
void L1::turn() {
	//shape = (shape + 1) % 4;     //��������������һ����һ����תʧ����������ת
	for (int i = 1; i <= 4; i++) {
		shape = (shape + i) % 4;
		if (check(this->getblock())) {
			return;
		}
		else { continue; }
	}
}
L1::~L1() {
	num--;
	delete c;
	c = nullptr;
}
	