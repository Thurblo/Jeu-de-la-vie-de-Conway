#include "Console.h"

void Console::run() {
	std::cout << "cb iteration ?" << std::endl;

	std::cin >> this->nb_iteration_asked;
	std::cout << "quel fichier ?" << std::endl;
	std::string file;
	std::cin >> file;

	GridLoadSave gls;

	Grid grid = gls.load(file);
	game.setGrid(grid);

	int nb_iteration = 0;
	while (nb_iteration < nb_iteration_asked) {
		game.iteration();
		nb_iteration++;
	}
	gls.save(grid, file);
}
