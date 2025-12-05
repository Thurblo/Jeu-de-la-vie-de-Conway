#include "GridRender.h"

GridRender::GridRender(Grid& grid) :
	grid(grid), w(grid.GetWidth()) {
	cellSize = 600 / w;
}

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
	sf::RectangleShape cell(sf::Vector2f(static_cast<float>(cellSize), static_cast<float>(cellSize)));

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
	//pour dessiner la grille 

	sf::Color gridLineColor = sf::Color(50, 50, 50);
	const float LINE_THICKNESS = 1.0f;

	for (int x = 0; x <= w; ++x) {
		sf::RectangleShape verticalLine(sf::Vector2f(LINE_THICKNESS, static_cast<float>(h * cellSize)));
		verticalLine.setPosition({ static_cast<float>(x * cellSize), 0.0f });
		verticalLine.setFillColor(gridLineColor);
		window.draw(verticalLine);
	}
	for (int y = 0; y <= h; ++y) {
		sf::RectangleShape horizontalLine(sf::Vector2f(static_cast<float>(w * cellSize), LINE_THICKNESS));
		horizontalLine.setPosition({ 0.0f, static_cast<float>(y * cellSize) });
		horizontalLine.setFillColor(gridLineColor);
		window.draw(horizontalLine);
	}
}

