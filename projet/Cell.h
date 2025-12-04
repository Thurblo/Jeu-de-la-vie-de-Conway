#ifndef CELLS_H
#pragma once
class Cell {
public :
	void setIsAlive(bool isAlive);
	bool getIsAlive();
	int getX();
	int getY();
	Cell();
private : 
	bool isAlive = false;
	int x;
	int y;
};
#endif