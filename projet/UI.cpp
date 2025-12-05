#include "UI.h"

UI::UI()
    : window(sf::VideoMode({ 800, 600 }), "Game of Life") {
    window.setFramerateLimit(60);

}


void UI::show() {
	GridRender gr(game.getGrid()); //ajout d'un argument dans ce constructeur qui emetait une erreur empechant le lancement du code
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

            // clic souris pour creer ou tuer des cellules 
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
                    std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;
                    sf::Vector2i gridPos = gr.convertWindowCoordinateToGridCoordinate(mouseButtonPressed->position);
                    std::cout << "grid x: " << gridPos.x << std::endl;
                    std::cout << "grid y: " << gridPos.y << std::endl;
                    //checker que gridPos est dans les dimensions de la grille
                    Cell& c = game.getGrid().GetCell(gridPos.x, gridPos.y); 
                    c.setIsAlive(!c.getIsAlive());
                }
            }

            //ajout de quand fleche de droite appuyee on avance de 1 iteration 
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Right)
                {
                    game.iteration();
                    std::cout << "Iteration avancee par fleche droite." << std::endl;
                }
            }
        }
        window.clear(sf::Color::Black);
        gr.drawGrid(window, game.getGrid());
        window.draw(playButtonNotPressedSprite);
        window.display();
    }
}