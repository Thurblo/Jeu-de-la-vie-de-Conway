#include "Game.h"

Game::Game() : grid(50, 50) {

}

Game::Game(Grid g) : grid(g) {

}

void Game::setGrid(Grid g)
{
	this->grid = g;
}

Grid& Game::getGrid()
{
	return this->grid;
}


void Game::iteration() {

	Grid nextGrid(grid.GetWidth(), grid.GetHeight());
	for (int x = 0; x < grid.GetWidth(); ++x) {
		for (int y = 0; y < grid.GetHeight(); ++y) {
			if (grid.GetNeighborAliveCount(x, y) == 3 && grid.GetCell(x, y).getIsAlive() == false) {
				nextGrid.GetCell(x, y).setIsAlive(true);
			}
			if (grid.GetCell(x, y).getIsAlive() == true && grid.GetNeighborAliveCount(x, y) == 2 || grid.GetNeighborAliveCount(x, y) == 3) {
				nextGrid.GetCell(x, y).setIsAlive(true);
			}
			else {
				nextGrid.GetCell(x, y).setIsAlive(false);
			}
		}
	}
	grid = nextGrid;

}



