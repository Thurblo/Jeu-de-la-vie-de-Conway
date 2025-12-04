#ifndef GRIDRENDER_H
#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
class GridRender {
public:
	void drawgrid(sf::RenderWindow& window, Grid& grid, int cellSize);
	int getCellSize();
private:
	int cellSize = 20;
};


#endif