#include "UI.h"
#include <iostream>

UI::UI()
    : window(sf::VideoMode({ 800, 600 }), "Game of Life") {
    window.setFramerateLimit(60);
}

void UI::show() {
    GridRender gr(game.getGrid());

    // pour evite clignotement
    sf::Vector2i lastEditedPos(-1, -1);

    sf::Texture playButtonNotPressed("playButtonNotPressed.png");
    sf::Sprite playButtonNotPressedSprite(playButtonNotPressed);
    playButtonNotPressedSprite.setPosition(sf::Vector2f(650, 50));

    sf::Texture playButtonPressed("playButtonPressed.png");
    sf::Sprite playButtonPressedSprite(playButtonPressed);

    bool isPlaying = false;

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				// fleche droite pour avancer d'une itération
                if (keyPressed->code == sf::Keyboard::Key::Right) {
                    game.iteration();
                }
                
                // Touche R pour reset 
                if (keyPressed->code == sf::Keyboard::Key::R) {
                    game.getGrid().clear(); 
                    std::cout << "Grille Reset " << std::endl;
                    isPlaying = false;
                }

                // barre espace automatique
                if (keyPressed->code == sf::Keyboard::Key::Space) {
					isPlaying = !isPlaying;
                    window.setFramerateLimit(10);
                    std::cout << (isPlaying ? "Lecture auto..." : "Pause.") << std::endl;
                    
                }
                
            }
        }
        // maintien de souris (clic gauche)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

            // verifie que la fenêtre est active
            if (window.hasFocus()) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                sf::Vector2i gridPos = gr.convertWindowCoordinateToGridCoordinate(mousePos);

                Grid& grid = game.getGrid();

                // verifie les limites
                if (gridPos.x >= 0 && gridPos.x < grid.GetWidth() &&
                    gridPos.y >= 0 && gridPos.y < grid.GetHeight()) {

                    // On modifie que si on change de case
                    if (gridPos != lastEditedPos) {
                        Cell& c = grid.GetCell(gridPos.x, gridPos.y);
                        c.setIsAlive(!c.getIsAlive()); 
                        lastEditedPos = gridPos;
                    }
                }
            }
        }
        else {
            lastEditedPos = sf::Vector2i(-1, -1);
        }

        //pour mode auto
        if (isPlaying) {
            game.iteration();
        }

        window.clear(sf::Color::Black);
        gr.drawGrid(window, game.getGrid());
        window.draw(playButtonNotPressedSprite);

        window.display();
    }
}