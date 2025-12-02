#ifndef GAME_H
#pragma once
#include "Cells.h"
#include "Grid.h"

class Game {
public : 
	int getNbIteration();
	int getNbIterationAsked();
	void setNbIterationAsked(int nb_iteration_asked);
	void iteration(Grid& grid,int nb_iteration_asked);
	

private : 
	int nb_iteration;
	int nb_iteration_asked;
};


#endif