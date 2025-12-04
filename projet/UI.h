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

private:
	sf::RenderWindow window;
	Game game;
};
