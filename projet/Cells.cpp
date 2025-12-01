#include "Cells.h"

int Cells::getX() {
	return this->x;
}

int Cells::getY() {
	return this->y;
}

bool Cells::getIsAlive() {
	return this->isAlive;
}

Cells::Cells(int x, int y, bool isAlive) : x(x), y(y){}