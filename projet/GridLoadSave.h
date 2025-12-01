#ifndef GRIDLOADSAVE_H
#pragma once

#include <iostream>
#include <string>
#include "Grid.h"

class GridLoadSave {
public:
	Grid load(const std::string& filename);
	void save(const std::Grid& grid, const std::string& filename);
};

#endif