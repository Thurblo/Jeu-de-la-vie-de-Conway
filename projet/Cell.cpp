#include "Cell.h"

void Cell::setIsAlive(bool isAlive) {
	this->isAlive = isAlive;
}
int Cell::getX() {
	return this->x;
}

int Cell::getY() {
	return this->y;
}

bool Cell::getIsAlive() {
	return this->isAlive;
}

Cell::Cell() : isAlive(false){}