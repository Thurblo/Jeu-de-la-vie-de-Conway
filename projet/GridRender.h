#ifndef GRIDRENDER_H
#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
class GridRender {
public:
	GridRender(Grid& grid);
	void drawGrid(sf::RenderWindow& window, Grid& grid);
	int getCellSize();
	sf::Vector2i convertWindowCoordinateToGridCoordinate(sf::Vector2i mousePos);
private:
	Grid grid;
	int w;
	int cellSize;
};


#endif