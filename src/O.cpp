#include "O.h"
#include"public.h"
extern int x, y, shape,nowcolor;
extern COLORREF colors[7];
extern bool land;
O::O() {  num++; }
int* O::getblock() { return block[shape]; };
void O::setcolor(int R, int G, int B) {
	c->setcolor(R, G, B);
}
void O::draw(int next_x, int next_y) {
	int temp_x, temp_y;
	for (int i = 0; i < 4; i++) {
		temp_x = next_x + 72 * (this->getblock()[i] % 4 - 1);   //һ��Ҫע��ǡ�������������Ȼdebug�ǳ�ʹ��
		temp_y = next_y + 72 * (this->getblock()[i] / 4);
		if (this->getblock()[i] % 4 == 0) { temp_x += 72 * 4; temp_y -= 72; }
		Drawblock(temp_x, temp_y, c->getcolor());
	}
};
void O::operator++() {
	x += 72;
	if (check(this->getblock())) {
		return;
	}
	else {
		x -= 72;
	}
}
void O::operator--() {
	x -= 72;
	if (check(this->getblock())) {
		return;
	}
	else {
		x += 72;
	}
}
void O::fall() {
	y += 72;
	if (check(this->getblock())) {
		return;
	}
	else {
		y -= 72;
		land = !land;
	}
}
void O::turn() {
	//shape = (shape + 1) % 4;     //��������������һ����һ����תʧ����������ת
	for (int i = 1; i <= 4; i++) {
		shape = (shape + i) % 4;
		if (check(this->getblock())) {
			return;
		}
		else { continue; }
	}
}
O::~O() {
	num--;
	delete c;
	c = nullptr;
};


