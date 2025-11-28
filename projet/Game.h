#ifndef GAME_H
#pragma once

class Game {
public : 
	int getNbIteration();
	int getNbIterationAsked();
	void iteration();
	void rules(bool isAlive);
private : 
	int nb_iteration;
	int nb_iteration_asked;
};


#endif