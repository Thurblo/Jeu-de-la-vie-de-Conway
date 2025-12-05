#include "UI.h"
#include <iostream>

UI::UI()
    : window(sf::VideoMode({ 800, 600 }), "Game of Life") {
    window.setFramerateLimit(120);
}

void UI::show() {
    GridRender gr(game.getGrid());

    // pour evite clignotement lors du maintien souris 
    sf::Vector2i lastEditedPos(-1, -1);

    sf::Texture btnNotPressed;
    btnNotPressed.loadFromFile("playButtonNotPressed.png");

    sf::Texture btnPressed;
    btnPressed.loadFromFile("playButtonPressed.png");

    sf::Sprite buttonSprite(btnNotPressed);
    buttonSprite.setPosition(sf::Vector2f(650, 50));

    bool isPlaying = false;

    unsigned int framerate = 30;

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // BOUTON PLAY / PAUSE
            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseEvent->button == sf::Mouse::Button::Left) {

                    sf::Vector2i pixelPos = { mouseEvent->position.x, mouseEvent->position.y };

                    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                    // pour check si on est dans la position du bouton
                    if (worldPos.x >= 650 && worldPos.x <= 750 &&
                        worldPos.y >= 75 && worldPos.y <= 125) {

                        isPlaying = !isPlaying;

                        // changement de l'image en fonction de l'etat du mode auto
                        if (isPlaying) buttonSprite.setTexture(btnPressed);
                        else buttonSprite.setTexture(btnNotPressed);
                    }
                }
            }




            // CLAVIER
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
                    window.setFramerateLimit(framerate);
                    std::cout << (isPlaying ? "Lecture auto..." : "Pause.") << std::endl;  
                }
                if (keyPressed->code == sf::Keyboard::Key::Up) {
                    framerate = framerate * 2;
                    window.setFramerateLimit(framerate);
                    std::cout << "vitesse multiplie par 2" << std::endl;
                }
                if (keyPressed->code == sf::Keyboard::Key::Down) {
                    framerate = framerate / 2;
                    window.setFramerateLimit(framerate);
                    std::cout << "vitesse divise par 2" << std::endl;
                }
            }
        }
        // maintien de souris (clic gauche)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

            // verifie que la fenêtre est active
            if (window.hasFocus()) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                //ajout pour convertir les donnees fenetre en monde 
                sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                sf::Vector2i gridPos = gr.convertWindowCoordinateToGridCoordinate(sf::Vector2i(worldPos));

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
        window.draw(buttonSprite);

        window.display();
    }
}