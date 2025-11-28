#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <optional> // Nécessaire pour gérer le retour de pollEvent ahahahhaahahaha

const int cellSize = 10;
const int gridWidth = 80;
const int gridHeight = 80;
int arthur = 2;

std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

void initializeGrid() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Correction cast et nullptr
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;
        }
    }
}

void renderGrid(sf::RenderWindow& window) {
    window.clear();

    // SFML 3 préfère les Vector2f explicites
    sf::RectangleShape cell(sf::Vector2f(static_cast<float>(cellSize - 1), static_cast<float>(cellSize - 1)));

    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) {
                // Conversion explicite en float pour éviter les warnings/erreurs
                cell.setPosition({ static_cast<float>(x * cellSize), static_cast<float>(y * cellSize) });
                window.draw(cell);
            }
        }
    }
    window.display();
}

int main() {
    // SFML 3: VideoMode prend un Vector2u (entiers non signés). 
    // On utilise les accolades {} pour construire le vecteur à la volée.
    sf::RenderWindow window(sf::VideoMode({ gridWidth * cellSize, gridHeight * cellSize }), "Game of Life");

    initializeGrid();

    while (window.isOpen()) {
        // --- CHANGEMENT MAJEUR SFML 3.0 ---
        // pollEvent retourne maintenant un std::optional
        while (const std::optional event = window.pollEvent()) {
            // On vérifie le type de l'événement avec .is<Type>()
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        // ----------------------------------

        renderGrid(window);

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}