#include "GridRender.h"

int GridRender::getCellSize() {
	return cellSize;
}

void GridRender::drawgrid(sf::RenderWindow& window, Grid& grid,int cellSize) {
    window.clear();
    
    int w = grid.GetWidth();
    int h = grid.GetHeight();

    // SFML 3 préfère les Vector2f explicites
    sf::RectangleShape cell(sf::Vector2f(static_cast<float>(cellSize - 1), static_cast<float>(cellSize - 1)));

    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            if (grid.GetCells(x, y).getIsAlive()) {
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
    
