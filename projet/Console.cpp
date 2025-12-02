#include "Console.h"
#include "GridLoadSave.h"
#include <iostream>   
#include <filesystem>

namespace fs = std::filesystem;

//Constructeur
Console::Console(Game& gamePtr, int nbIterations, std::string file)
	: game(&gamePtr), iterations(nbIterations), inputFile(file) {
}

void Console::run() {

	GridLoadSave::load(inputFile);

	std::string outputFile = inputFile + "_out";

	if(!fs::exists(outputFile)) {
		fs::create_directory(outputFile);
	}

	std::cout << "Mode Console: Calcul de" << iterations << "iterations..." << std::endl;

	for (int i = 0; i < iterations; i++) {

		game->update(); // pour calculer l'etape suivante on a besoin de l'update dans game

		std::cout << "Iteration" << (i + 1) << "effectue." << std::endl;
	}

	std::cout << "Fichier contenant l'iteration" << iterations << "sauvegardee." << std::endl;
	std::string outFile = outputFile + "iter_" + std::to_string(iterations) + ".txt";
	GridLoadSave::save(game->getGrid(), outFile);

	std::cout << "Termine." << std::endl;
}