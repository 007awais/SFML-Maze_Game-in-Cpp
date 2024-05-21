#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H
#include"/Users/apple/Downloads/sfml-macos/src/generateMaze.h"
#include <SFML/Graphics.hpp>
#include <iostream> 

void showGameOver() {
    // Create a new window for "Game Over"
    sf::RenderWindow gameOverWindow(sf::VideoMode(400, 200), "Game Over");

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/apple/Downloads/sfml-macos/src/GameOver.jpeg")) {
        std::cerr << "Failed to load background image!" << std::endl;
        return;
    }

    // Create a sprite for the background image
    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(400.f / backgroundTexture.getSize().x, 200.f / backgroundTexture.getSize().y);

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

        // Display the window
        gameOverWindow.display();
    }
}


void displayStats(int score) {
    sf::RenderWindow window(sf::VideoMode(400, 200), "Player Stats");
    sf::Font font;
    if (!font.loadFromFile("/Users/apple/Downloads/sfml-macos/Roboto/Roboto-Light.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setString("Score: " + std::to_string(score));
    text.setPosition(10, 10);

    // Add colored background
    sf::RectangleShape background(sf::Vector2f(400.f, 200.f));
    background.setFillColor(sf::Color(200, 200, 200)); // Choose your desired color
    window.draw(background);

    window.draw(text);
    window.display();

    // Wait for the window to be closed
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}




#endif // GAME_OVER_SCREEN_H
