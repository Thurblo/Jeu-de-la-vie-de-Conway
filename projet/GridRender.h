#ifndef GRIDRENDER_H
#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
class GridRender {
public:
	void drawGrid(sf::RenderWindow& window, Grid& grid);
	int getCellSize();
	sf::Vector2i convertWindowCoordinateToGridCoordinate(sf::Vector2i mousePos);
private:
	int cellSize = 20;
};


#endif