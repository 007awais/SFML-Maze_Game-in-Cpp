#ifndef startGame_H
#define startGame_H

#include <SFML/Graphics.hpp>
#include <iostream>

class startGame {
public:


    void run() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Enchanted Labyrinth");
        window.setFramerateLimit(60);

        // Load background texture
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("//Users//apple//Downloads//sfml-macos//src//startgamenew.jpeg")) {
            std::cout << "Error loading background image" << std::endl;
            return; // Exit the function if texture loading fails
        }

        // Create sprite for background
        sf::Sprite backgroundSprite(backgroundTexture);

        // Scale the background sprite to fit the window size
        backgroundSprite.setScale(window.getSize().x / backgroundSprite.getLocalBounds().width, 
                                   window.getSize().y / backgroundSprite.getLocalBounds().height);

        sf::Font font;
        if (!font.loadFromFile("//Users//apple/Downloads//sfml-macos//Roboto//Roboto-Italic.ttf")) {
            std::cout << "Error opening font file" << std::endl;
            return; // Exit the function if font loading fails
        }

        sf::Text startText;
        startText.setFont(font);
        startText.setString("Unleash Your Imagination:\nThere are no limits to what you can achieve.\nLet your creativity soar and carve your path through the stars.");
        startText.setCharacterSize(24);
        startText.setFillColor(sf::Color::Red);
        startText.setStyle(sf::Text::Bold);
        
        // Calculate text bounds
        sf::FloatRect textBounds = startText.getLocalBounds();

        // Set text position to center
        startText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        startText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

        // Main loop for rendering
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // Clear the window
            window.clear();

            // Draw the background
            window.draw(backgroundSprite);

            // Draw the text
            window.draw(startText);

            // Display everything
            window.display();
        }
    }
};

#endif // startGame_H
