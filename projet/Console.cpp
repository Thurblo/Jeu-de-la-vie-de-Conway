#include "Console.h"
#include "GridLoadSave.h"
#include "Grid.h"
#include "Cells.h"
#include <iostream>   
#include <filesystem>

namespace fs = std::filesystem;

void Console::run(GridLoadSave& gls) {
	Game game;
	std::cout << "cb iteration ?" << std::endl;
	
	std::cin >> this->nb_iteration_asked;
	//game.setNbIterationAsked(nb);
	std::cout << "quelle fichier ?" << std::endl;
	std::string file;
	std::cin >> file;
	Grid grid = gls.load(file);
	for (int y = 0; y < grid.GetHeight(); ++y) {
		for (int x = 0; x < grid.GetWidth(); ++x) {
			Cells& cells = grid.GetCells(x, y);
			game.iteration(grid, nb_iteration_asked);
		}
	}
	gls.save(grid, file);
}
