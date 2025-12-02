#include "Game.h"
#include "Cells.h"
#include "Grid.h"

int Game::getNbIteration(){
	return this->nb_iteration;
}

int Game::getNbIterationAsked() {
	return this->nb_iteration_asked;
}

void Game::iteration(Grid& grid,Cells& cells) {
	Cells& GetCells(int x,int y);
	while (nb_iteration < nb_iteration_asked) {
		for (int x = 0; x < grid.GetWidth(); ++x) {
			for (int y = 0; y < grid.GetHeight(); ++y) {
				if (grid.GetNeighbor(x, y) == 3 && cells.getIsAlive() == false) {
					cells.setIsAlive(true);
				}
				if (cells.getIsAlive() == true && grid.GetNeighbor(x, y) == 2 || 3) {
					cells.setIsAlive(true);
				}
				else {
					cells.setIsAlive(false);
				}
			}
		}
		nb_iteration++;
	}
}

