#include "UI.h"

UI::UI()
    : window(sf::VideoMode({ 800, 600 }), "Game of Life") {
    window.setFramerateLimit(60);

}


void UI::show() {
    GridRender gr(game.getGrid()); //ajout d'un argument dans ce constructeur qui emetait une erreur empechant le lancement du code
    sf::Vector2i lastEditedPos(-1, -1);
    sf::Texture playButtonNotPressed("playButtonNotPressed.png");
    sf::Sprite playButtonNotPressedSprite(playButtonNotPressed);
    playButtonNotPressedSprite.setPosition(sf::Vector2f(650, 50));

    sf::Texture playButtonPressed("playButtonPressed.png");
    sf::Sprite playButtonPressedSprite(playButtonPressed);

    while (window.isOpen()) {

        // Gestion des événements (fermeture, clavier, etc.)
        while (const std::optional event = window.pollEvent()) {

            // L'utilisateur ferme la fenêtre
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Right) {
                    game.iteration();
                    std::cout << "Iteration avancee par fleche droite." << std::endl;

                    // clic souris pour creer ou tuer des cellules 
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        sf::Vector2i gridPos = gr.convertWindowCoordinateToGridCoordinate(mousePos);
                        std::cout << "grid x: " << gridPos.x << std::endl;
                        std::cout << "grid y: " << gridPos.y << std::endl;
                        //checker que gridPos est dans les dimensions de la grille
                        Grid& grid = game.getGrid(); // Référence raccourcie
                        if (gridPos.x >= 0 && gridPos.x < grid.GetWidth() && gridPos.y >= 0 && gridPos.y < grid.GetHeight()) {
                            if (gridPos != lastEditedPos) {
                                Cell& c = game.getGrid().GetCell(gridPos.x, gridPos.y);
                                c.setIsAlive(!c.getIsAlive());
                                lastEditedPos = gridPos;
                            }
                        }
                    }
                }
            }
            window.clear(sf::Color::Black);
            gr.drawGrid(window, game.getGrid());
            window.draw(playButtonNotPressedSprite);
            window.display();
        }
    }
}