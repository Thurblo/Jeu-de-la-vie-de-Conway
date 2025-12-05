#include "Grid.h"

int Grid::GetHeight() {
	return height;
}
int Grid::GetWidth() {
	return width;
}
Grid::Grid(int width, int height)
	: width(width), height(height), cells(height, std::vector<Cell>(width)) {}//vector<T> nom(nbElements, valeurInitiale)

void Grid::resize(int w, int h) {
	width = w;
	height = h;
	//TODO agrandir ou supprimer les cellules en fonction
}

Cell& Grid::GetCell(int x, int y) {
	return cells[y][x];
}

int Grid::GetNeighborAliveCount(int x, int y) {
    int count = 0;

    // balayage
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if (i == 0 && j == 0) continue;

            // utilisation de modulo pour la grille torique 
            int voisinX = (x + i + width) % width;
            int voisinY = (y + j + height) % height;

            if (cells[voisinY][voisinX].getIsAlive()) {
                count++;
            }
        }
    }
    return count;
}

void Grid::clear() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cells[y][x].setIsAlive(false);
        }
    }
}
