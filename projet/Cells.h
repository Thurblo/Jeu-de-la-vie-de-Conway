#ifndef CELLS_H
#pragma once
class Cells {
public :
	bool getIsAlive();
	int getX();
	int getY();
private : 
	bool isAlive;
	int x;
	int y;
};
#endif