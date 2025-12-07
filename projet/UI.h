#pragma once
#include <SFML/Graphics.hpp>
#include "GridRender.h"
#include "Grid.h"
#include "GridLoadSave.h"
#include "Game.h"

class UI {
public:
	void show();
	UI();
	unsigned int getFrameRate();

private:
	sf::RenderWindow window;
	Game game;
	unsigned int frameRate = 30;
};
