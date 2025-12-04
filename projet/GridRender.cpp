#include "GridRender.h"

int GridRender::getCellSize() {
	return cellSize;
}

sf::Vector2i GridRender::convertWindowCoordinateToGridCoordinate(sf::Vector2i mousePos)
{
	return sf::Vector2i(mousePos.x / cellSize, mousePos.y / cellSize);
}


void GridRender::drawGrid(sf::RenderWindow& window, Grid& grid) {
	window.clear();

	int w = grid.GetWidth();
	int h = grid.GetHeight();

	// SFML 3 préfère les Vector2f explicites
	const int DECALAGE_BORDURE = 1;
	sf::RectangleShape cell(sf::Vector2f(static_cast<float>(cellSize - DECALAGE_BORDURE), static_cast<float>(cellSize - DECALAGE_BORDURE)));

	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			if (grid.GetCell(x, y).getIsAlive()) {
				cell.setFillColor(sf::Color::White);
			}
			else {
				cell.setFillColor(sf::Color::Black);
			}
			cell.setPosition({ static_cast<float>(x * cellSize), static_cast<float>(y * cellSize) });
			window.draw(cell);
		}
	}
}

