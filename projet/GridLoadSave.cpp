// Ce fichier permet de charger un fichier et de sauvegarder le fichier 

#include <iostream>
#include <fstream>
#include "Grid.h"
#include "GridLoadSave.h"

Grid GridLoadSave::load(const std::string& filename) {
	std::ifstream GameLife(filename);
	if (!GameLife.is_open()) {}

	int width;
	int height;
	GameLife >> width >> height;

	Grid grid(width, height);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int state;
			GameLife >> state;

			grid.GetCells(x, y).setIsAlive(state == 1);
		}
	}
	return grid;
}

void GridLoadSave::save(Grid& grid,const std::string& filename) {
	std::ofstream Gamelife(filename);
	if (!Gamelife.is_open()) {}

	int width = grid.GetWidth();
	int height = grid.GetHeight();

	Gamelife << width << " " << height;


	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			Gamelife << (grid.GetCells(x, y).getIsAlive() ? true : false);
			Gamelife << " ";
		}
		Gamelife << "\n";
	}



}