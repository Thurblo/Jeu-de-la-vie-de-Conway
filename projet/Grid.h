#ifndef GRID_H
#pragma once
#include <vector>
#include "Cell.h"

class Grid {
public:
	int GetWidth();
	int GetHeight();
	Grid(int width, int height);
	void resize(int width, int height);
	Cell& GetCell(int x, int y);
	int GetNeighborAliveCount(int x, int y);
	void clear();

private:
	int width;
	int height;
	std::vector<std::vector<Cell>> cells;

};



#endif


