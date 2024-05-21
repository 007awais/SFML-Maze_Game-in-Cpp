#include <SFML/Graphics.hpp>
#include <iostream>

void exitGame() {
    // Create a new window for "Game Over"
    sf::RenderWindow gameOverWindow(sf::VideoMode(600, 1000), "The-End");

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/apple/Downloads/sfml-macos/src/game_won.png")) {
        std::cerr << "Failed to load background image!" << std::endl;
        return;
    }

    // Create a sprite for the background image
    sf::Sprite backgroundSprite(backgroundTexture);

    // Main loop for the "Game Over" window
    while (gameOverWindow.isOpen()) {
        sf::Event event;
        while (gameOverWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameOverWindow.close();
            }
        }

        // Clear the window
        gameOverWindow.clear();

        // Draw the background image
        gameOverWindow.draw(backgroundSprite);

        // Display the contents of the window
        gameOverWindow.display();
    }
}
