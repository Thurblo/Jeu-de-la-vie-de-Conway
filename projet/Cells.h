#ifndef CELLS_H
#pragma once
class Cells {
public :
	void setIsAlive(bool isAlive);
	bool getIsAlive();
	int getX();
	int getY();
	Cells(int x, int y, bool isAlive);
private : 
	bool isAlive = false;
	int x;
	int y;
};
#endif