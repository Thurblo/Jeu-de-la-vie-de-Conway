#include "Console.h"

void Console::run() {
	std::cout << "Combien d'iteration souhaitez-vous effectuer ?" << std::endl;

	std::cin >> this->nb_iteration_asked;
	std::cout << "Comment se nomme votre fichier que souhaitez charger ?" << std::endl;
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
	
	std::string outputFile = file + "_out.txt"; // pour crée un nouveau fichier de sortie pour eviter l'ecrasement des resultats
	gls.save(game.getGrid(), outputFile); // ajout du parametre game.getGrid() pour recuperer la grille produite dans game
	std::cout << "Sauvegarde terminee dans "<< outputFile << std::endl; // ça met juste la phrase de fin 
}
