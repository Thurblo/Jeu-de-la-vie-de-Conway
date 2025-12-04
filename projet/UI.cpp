#include "UI.h"

void UI::windowDraw(sf::RenderWindow& window,Grid& grid,GridRender& gr) {
    int cs = gr.getCellSize();

    while (window.isOpen()) {

        // Gestion des événements (fermeture, clavier, etc.)
        while (const std::optional event = window.pollEvent()) {

            // L'utilisateur ferme la fenêtre
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            
            sf::RenderWindow window(sf::VideoMode({ grid.GetWidth() * gr.getCellSize(), grid.GetHeight() * gr.getCellSize() }), "Game of Life");
            window.display();
        }
}