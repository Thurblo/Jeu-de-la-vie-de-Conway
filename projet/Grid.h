#ifndef GRID_H
#pragma once
#include <vector>
#include "Cells.h"

class Grid {
public:
	int GetWidth();
	int GetHeigt();
	Grid(int width, int height);

private : 
	int width;
	int heigt;
	std::vector<std::vector<Cells>>cells;
	
};



#endif


