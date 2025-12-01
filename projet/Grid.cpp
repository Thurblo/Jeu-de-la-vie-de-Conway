#include "Grid.h"

int Grid::GetHeight() {
	return height;
}
int Grid::GetWidth() {
	return width;
}
Grid::Grid(int width, int height)
   : width(width),height(height) {
	resize(width, height);
	cells.clear();
	std::vector<std::vector<Cells>>cells;

}

void Grid::resize(int w, int h) {
	width = w;
	height = h;
}
Cells& Grid::GetCells(int x, int y) {
	return cells[x][y];
}

void Grid::GetNeighbor(int x, int y) {
	int count = 0;
	GetCells(x, y);
	if (x - 1 >= 0 && y - 1 >= 0) {
		if (cells[x - 1][y - 1].getIsAlive()) {
			count++;
		}
	}
	if (y - 1 >= 0) {
		if (cells[x][y - 1].getIsAlive()) {
			count++;
		}
	}
	if (y - 1 >= 0 && x + 1 <= width) {
		if (cells[x + 1][y - 1].getIsAlive()) {
			count++;
		}
	}
	if (x - 1 >= 0) {
		if (cells[x - 1][y].getIsAlive()) {
			count++;
		}
	}
	if (x + 1 <= width) {
		if (cells[x + 1][y].getIsAlive()) {
			count++;
		}
	}
	if (x - 1 >= 0 && y + 1 <= height) {
		if (cells[x - 1][y + 1].getIsAlive()) {
			count++;
		}
	}
	if (y + 1 <= height) {
		if (cells[x][y + 1].getIsAlive()) {
			count++;
		}
	}
	if (y + 1 <= height && x + 1 <= width) {
		if (cells[x + 1][y + 1].getIsAlive()) {
			count++;
		}
	}
}
