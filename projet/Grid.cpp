#include "Grid.h"

int Grid::GetHeight() {
	return height;
}
int Grid::GetWidth() {
	return width;
}
Grid::Grid(int width, int height)
	: width(width), height(height) {
	cells.resize(height);
	for (int y = 0; y < height; y++) {
		cells[y].resize(width);
		for (int x = 0; x < width; x++) {
			cells[y][x] = Cells();
		}
	}
}

void Grid::resize(int w, int h) {
	width = w;
	height = h;
}
Cells& Grid::GetCells(int x, int y) {
	return cells[y][x];
}

int Grid::GetNeighbor(int x, int y) {
	int count = 0;
	if (x - 1 >= 0 && y - 1 >= 0) {
		if (cells[y - 1][x - 1].getIsAlive()) {
			count++;
		}
	}
	if (x - 1 >= 0) {
		if (cells[y][x - 1].getIsAlive()) {
			count++;
		}
	}
	if (x - 1 >= 0 && y + 1 <= height-1) {
		if (cells[y + 1][x - 1].getIsAlive()) {
			count++;
		}
	}
	if (y - 1 >= 0) {
		if (cells[y - 1][x].getIsAlive()) {
			count++;
		}
	}
	if (y + 1 <= height-1) {
		if (cells[y + 1][x].getIsAlive()) {
			count++;
		}
	}
	if (y - 1 >= 0 && x + 1 <=width-1) {
		if (cells[y - 1][x + 1].getIsAlive()) {
			count++;
		}
	}
	if (x + 1 <= width-1) {
		if (cells[y][x + 1].getIsAlive()) {
			count++;
		}
	}
	if (y + 1 <= height-1 && x + 1 <= width-1) {
		if (cells[y + 1][x + 1].getIsAlive()) {
			count++;
		}
	}
	return count;
}
