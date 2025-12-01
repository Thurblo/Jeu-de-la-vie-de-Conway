#ifndef GRID_H
#pragma once
#include <vector>
#include "Cells.h"

class Grid {
public:
	int GetWidth();
	int GetHeight();
	Grid(int width, int height);
	void resize(int width, int height);
	Cells& GetCells(int x, int y);
	void GetNeighbor(int x, int y);
private : 
	int width;
	int height;
	std::vector<std::vector<Cells>>cells;
	
};



#endif


