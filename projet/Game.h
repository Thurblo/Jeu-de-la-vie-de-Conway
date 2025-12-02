#ifndef GAME_H
#pragma once

class Game {
public : 
	int getNbIteration();
	int getNbIterationAsked();
	void iteration();
	

private : 
	int nb_iteration;
	int nb_iteration_asked;
};


#endif