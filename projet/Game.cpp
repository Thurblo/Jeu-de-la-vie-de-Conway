#include "Game.h"
#include "Cells.h"
#include "Grid.h"

int Game::getNbIteration(){
	return this->nb_iteration;
}

int Game::getNbIterationAsked() {
	return this->nb_iteration_asked;
}
void Game::setNbIterationAsked(int nb) {
     nb = nb_iteration_asked;
}

void Game::iteration(Grid& grid,int nb_iteration_asked) {
	nb_iteration = 0;
	Cells& GetCells(int x,int y);
	while (nb_iteration < nb_iteration_asked) {
		Grid nextGrid(grid.GetWidth(), grid.GetHeight());
		for (int x = 0; x < grid.GetWidth(); ++x) {
			for (int y = 0; y < grid.GetHeight(); ++y) {
				if (grid.GetNeighbor(x, y) == 3 && grid.GetCells(x, y).getIsAlive() == false) {
					nextGrid.GetCells(x, y).setIsAlive(true);
				}
				if (grid.GetCells(x, y).getIsAlive() == true && grid.GetNeighbor(x, y) == 2 || grid.GetNeighbor(x, y) == 3) {
					nextGrid.GetCells(x, y).setIsAlive(true);
				}
				else {
					nextGrid.GetCells(x, y).setIsAlive(false);
				}
			}
		}
		nb_iteration++;
		grid = nextGrid;
	}
}



