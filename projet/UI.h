#pragma once
#include <SFML/Graphics.hpp>
#include "GridRender.h"
#include "Grid.h"
class UI {
public: 
	void windowDraw(sf::RenderWindow& window, Grid& grid);
	UI();

private :
	sf::RenderWindow window;
};
