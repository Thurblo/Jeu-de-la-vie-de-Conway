#ifndef CONSOLE_H
#pragma once
#include "GridLoadSave.h"
#include "Game.h"
#include <string>
#include "Grid.h"
#include <iostream>   



class Console {
private:
	Game game;

	std::string inputFile;
	int nb_iteration_asked;

public:
	void run();

};

#endif