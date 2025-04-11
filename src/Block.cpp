#include "Block.h"
#include"public.h"
extern int x, y;
extern bool land;
extern int  shape;
extern COLORREF colors[7];

COLORREF Block:: getcolor() {
		return c->getcolor();
	}
int Block::getnum() { return num; }
	
