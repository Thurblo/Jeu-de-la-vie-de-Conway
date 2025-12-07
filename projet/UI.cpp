#include "UI.h"
#include <iostream>

unsigned int UI::getFrameRate() {
    return this->frameRate;
};

UI::UI()
    : window(sf::VideoMode({ 800, 600 }), "Game of Life") {
    window.setFramerateLimit(frameRate);
}

void UI::show() {
    GridRender gr(game.getGrid());

    // pour evite clignotement lors du maintien souris 
    sf::Vector2i lastEditedPos(-1, -1);

    // clock
    sf::Clock gameClock; 
    sf::Time timeOfClick;
     
    // BOUTON PLAY / PAUSE
    sf::Texture playBtnNotPressed;
    playBtnNotPressed.loadFromFile("playButtonNotPressed.png");

    sf::Texture playBtnPressed;
    playBtnPressed.loadFromFile("playButtonPressed.png");

    sf::Sprite playBtnSprite(playBtnNotPressed);
    playBtnSprite.setPosition(sf::Vector2f(650, 50));

    bool playIsPlaying = false;

    // BOUTON X2
    bool x2IsPlaying = false;
    sf::Texture x2BtnNotPressed;
    x2BtnNotPressed.loadFromFile("X2ButtonNotPressed.png");

    sf::Texture x2BtnPressed;
    x2BtnPressed.loadFromFile("X2ButtonPressed.png");

    sf::Sprite x2BtnSprite(playBtnNotPressed);
    x2BtnSprite.setPosition(sf::Vector2f(650, 150));

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

                        playIsPlaying = !playIsPlaying;

                        // changement de l'image en fonction de l'etat du mode auto
                        if (playIsPlaying) playBtnSprite.setTexture(playBtnPressed);
                        else playBtnSprite.setTexture(playBtnNotPressed);
                    }
                }
            }

            // BOUTON X2
            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseEvent->button == sf::Mouse::Button::Left) {

                    sf::Vector2i pixelPos = { mouseEvent->position.x, mouseEvent->position.y };

                    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                    // pour check si on est dans la position du bouton
                    if (worldPos.x >= 650 && worldPos.x <= 750 &&
                        worldPos.y >= 175 && worldPos.y <= 225) {

                        frameRate = frameRate * 2;
                        window.setFramerateLimit(frameRate);
                        std::cout << "vitesse multiplie par 2" << std::endl;

            // changement de l'image pour 0.5s quand appuyer
                        x2BtnSprite.setTexture(x2BtnPressed);

                        timeOfClick = gameClock.getElapsedTime();
                        x2IsPlaying = true;
                    }
                }
            }
            if (x2IsPlaying) {
                sf::Time currentTime = gameClock.getElapsedTime();
                if ((currentTime - timeOfClick).asSeconds() >= 0.5f) {
                    x2BtnSprite.setTexture(x2BtnNotPressed);
                    x2IsPlaying = false;
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
                    playIsPlaying = false;
                }
                // barre espace automatique
                if (keyPressed->code == sf::Keyboard::Key::Space) {
					playIsPlaying = !playIsPlaying;
                    window.setFramerateLimit(frameRate);
                    std::cout << (playIsPlaying ? "Lecture auto..." : "Pause.") << std::endl;  
                }
                if (keyPressed->code == sf::Keyboard::Key::Up) {
                    frameRate = frameRate * 2;
                    window.setFramerateLimit(frameRate);
                    std::cout << "vitesse multiplie par 2" << std::endl;
                }
                if (keyPressed->code == sf::Keyboard::Key::Down) {
                    frameRate = frameRate / 2;
                    window.setFramerateLimit(frameRate);
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
        if (playIsPlaying) {
            game.iteration();
        }

        window.clear(sf::Color::Black);
        gr.drawGrid(window, game.getGrid());
        window.draw(playBtnSprite);
        window.draw(x2BtnSprite);

        window.display();
    }
}