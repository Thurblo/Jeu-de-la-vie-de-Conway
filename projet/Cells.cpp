#include "Cells.h"

void Cells::setIsAlive(bool isAlive) {
	this->isAlive = isAlive;
}
int Cells::getX() {
	return this->x;
}

int Cells::getY() {
	return this->y;
}

bool Cells::getIsAlive() {
	return this->isAlive;
}

Cells::Cells() : isAlive(false){}