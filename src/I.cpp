#include "I.h"
#include"public.h"
extern int x, y,shape;
extern COLORREF colors[7];
extern bool land;
	I::I() {  num++; }
	int*I:: getblock() { return block[shape]; };
	void I::setcolor(int R, int G, int B) {
		c->setcolor(R, G, B);
	}
	void I::draw(int next_x,int next_y) {
		int temp_x, temp_y;
		for (int i = 0; i < 4; i++) {
			temp_x = next_x + 72 * (this->getblock()[i] % 4 - 1);   //一定要注意恰好整除情况，不然debug非常痛苦
			temp_y = next_y + 72 * (this->getblock()[i] / 4);
			if (this->getblock()[i] % 4 == 0) { temp_x += 72 * 4; temp_y -= 72; }
			Drawblock(temp_x, temp_y, c->getcolor());
		}
	};
	void I::operator++(){
		x += 72;
		if (check(this->getblock())) {
			return;
		}
		else {
			x -= 72;
		}
	}
	void I::operator--() {
		x -= 72;
		if (check(this->getblock())) {
			return;
		}
		else {
			x += 72;
		}
	}
	void I::fall() {
		y += 72;
		if (check(this->getblock())) {
			return;
		}
		else {
			y -=72;
			land = !land;
		}
	}
	void I::turn() {
		//shape = (shape + 1) % 4;     //发现这样不合理，一旦有一种旋转失败则不能再旋转
		for (int i = 1; i <= 4; i++) {
			shape = (shape + i) % 4;
			if (check(this->getblock())) {
				return;
			}
			else { continue; }
		}
	}
	I::~I() {
		num--;
		delete c;
		c = nullptr;

		}
