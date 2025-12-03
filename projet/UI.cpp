#include "UI.h"
#include "Grid.h"
void UI::windowDraw(sf::RenderWindow& window) {
	sf::RenderWindow window(sf::VideoMode({ width * cellSize, gridHeight * cellSize }), "Game of Life");
}