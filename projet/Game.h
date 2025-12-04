#ifndef GAME_H
#pragma once
#include "Cell.h"
#include "Grid.h"

class Game {
public : 
	void iteration();

	Game();
	Game(Grid g);

	void setGrid(Grid g);
	Grid& getGrid();

private: 
	Grid grid;

};


#endif