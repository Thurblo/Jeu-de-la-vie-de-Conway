// Ce fichier permet de charger un fichier et de sauvegarder le fichier 

#include <iostream>
#include <fstream>
#include "Grid.h"
#include "GridLoadSave.h"

Grid GridLoadSave::load(const std::string& filename) {
	std::ifstream filestream(filename);
	if (!filestream.is_open()) {}

	int width;
	int height;
	filestream >> width >> height;

	Grid grid(width, height);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int state;
			filestream >> state;
			if (state == 1) {
				grid.GetCell(x, y).setIsAlive(true);
			}
		}
	}
	return grid;
}

void GridLoadSave::save(Grid& grid,const std::string& filename) {
	std::ofstream filestream(filename);
	if (!filestream.is_open()) {}

	int width = grid.GetWidth();
	int height = grid.GetHeight();

	filestream << width << " " << height << "\n";


	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			filestream << (grid.GetCell(x, y).getIsAlive() ? 1 : 0);
			filestream << " ";
		}
		filestream << "\n";
	}



}