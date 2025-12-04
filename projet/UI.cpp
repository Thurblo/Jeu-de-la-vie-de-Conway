#include "UI.h"

UI::UI()
    : window(sf::VideoMode({ 800, 600 }), "Game of Life") {
    window.setFramerateLimit(60);
}


void UI::windowDraw(sf::RenderWindow& window, Grid& grid) {
    GridRender gr;
    int Cellsize = gr.getCellSize();

    while (window.isOpen()) {

        // Gestion des événements (fermeture, clavier, etc.)
        while (const std::optional event = window.pollEvent()) {

            // L'utilisateur ferme la fenêtre
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        gr.drawgrid(window, grid, Cellsize);
        window.display();
    }
}