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
		game->update();

		std::string outFile = outputFile + "iter_" + std::to_string(i + 1) + ".txt";

		GridLoadSave::save(game->getGrid(), outFile);

		std::cout << "Iteration" << (i + 1) << "sauvegardee." << std::endl;
	}
	std::cout << "Termine." << std::endl;
}