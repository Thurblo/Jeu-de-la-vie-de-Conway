#pragma once

#include "Game.h"
#include <string>

class Console {
private:
	Game* game;
	int iterations;
	std::string inputFile;

public:
	Console(Game& gamePtr, int nbIterations, std::string file);
	void run();

};

