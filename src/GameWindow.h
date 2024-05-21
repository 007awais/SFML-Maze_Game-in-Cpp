#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>

// Function to run the game window
void runGameWindow() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Enchanted Labyrinth Explorer");
    window.setFramerateLimit(60);

      sf::Music music;
    if (!music.openFromFile("horro_sound.ogg")) {
        std::cerr << "Failed to load background music!" << std::endl;
        return; // Return if music loading fails
    }
    music.play();
    music.setLoop(true);
    //Load background image;
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background3.jpg")) {
        std::cerr << "Failed to load background image!" << std::endl;
        return;
    }
    sf::Sprite background(backgroundTexture);

    // Scale the background image to cover the entire window
    float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
    background.setScale(scaleX, scaleY);

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw background image
        window.draw(background);

        // Draw other game elements here...

        window.display();
    }
}

// Function to close the game window
void closeGameWindow(sf::RenderWindow& window) {
    window.close(); // Close the game window
}

#endif // GAMEWINDOW_H
