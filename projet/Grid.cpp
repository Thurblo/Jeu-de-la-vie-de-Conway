#include "Grid.h"

int Grid::GetHeigt() {
	return heigt;
}
int Grid::GetWidth() {
	return width;
}
Grid::Grid(int width, int heigt)
   : width(width),heigt(heigt) { }