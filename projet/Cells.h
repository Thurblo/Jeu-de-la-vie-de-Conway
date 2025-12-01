#ifndef CELLS_H
#pragma once
class Cells {
public :
	bool getIsAlive();
	int getX();
	int getY();
	Cells(int x, int y, bool isAlive);
private : 
	bool isAlive;
	int x;
	int y;
};
#endif