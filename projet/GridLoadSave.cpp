// Ce fichier permet de charger un fichier et de sauvegarder le fichier 

#include <iostream>
#include <fstream>
#include "Grid.h"

Grid GridLoadSave::load(const std::string& filename) {
	ifstream GameLife(filename);
	if (!GameLife.is_open()) {}

	int width;
	int height;
	GameLife >> width;
	GameLife >> height;

	Grid a(width, height);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int state;
			GameLife >> state;

			a.getCell(x, y)->setState(state == 1);
		}
	}
	return a;
}

void GridLoadSave::save(const std::grid& grid, const string& filename) {
	ofstream Gamelife(filename);
	if (!Gamelife.is_open()) {}

	int width = grid.getWidth();
	int height = grid.getHeight();

	Gamelife << widtth << " " << height;


	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			Gamelife << (grid.getCell(x, y)->getState() ? 1 : 0);
			Gamelife << " ";
		}
		Gamelife << "\n";
	}



}