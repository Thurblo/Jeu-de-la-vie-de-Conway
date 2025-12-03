#include "GridRender.h"

int GridRender::getCellSize(int cellSize) {
	return cellSize;
}

void GridRender::drawgrid(Grid& grid) {
    window.clear();

    // SFML 3 préfère les Vector2f explicites
    sf::RectangleShape cell(sf::Vector2f(static_cast<float>(cellSize - 1), static_cast<float>(cellSize - 1)));

    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) {
                // Conversion explicite en float pour éviter les warnings/erreurs
                cell.setPosition({ static_cast<float>(x * cellSize), static_cast<float>(y * cellSize) });
                window.draw(cell);
            }
        }
    }
    window.display();

}