#ifndef GAME_MENU_H
#define GAME_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "startGame.h"
#include"/Users/apple/Downloads/sfml-macos/src/generateMaze.h"
#include "/Users/apple/Downloads/sfml-macos/src/help.h"
#include "/Users/apple/Downloads/sfml-macos/src/Inventorymanagment.h"
#include"/Users/apple/Downloads/sfml-macos/src/item.txt"


startGame g;
AVLTree t;


class GameMenu {
public:
    void display() {
        // Create window
        sf::RenderWindow window(sf::VideoMode(800, 600), "Game Menu");
        window.setFramerateLimit(60);

        // Load background texture
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("//Users//apple//Downloads//sfml-macos//src//newbackground4.jpeg")) {
            std::cout << "Error loading background image" << std::endl;
            return; // Exit the function if texture loading fails
        }

        // Create sprite for background
        sf::Sprite backgroundSprite(backgroundTexture);
        float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
        float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
        backgroundSprite.setScale(scaleX, scaleY);

        // Load font
        sf::Font font;
        if (!font.loadFromFile("//Users//apple/Downloads//sfml-macos//Roboto//Roboto-BlackItalic.ttf")) {
            std::cout << "Error opening font file" << std::endl;
            return; // Exit the function if font loading fails
        }

        // Create text for each menu item
        sf::Text startText;
        startText.setFont(font);
        startText.setString("1. Start Game");
        startText.setCharacterSize(24);
        startText.setFillColor(sf::Color::Red);
        startText.setStyle(sf::Text::Bold);
        startText.setPosition(280, 200);

        sf::Text helpText;
        helpText.setFont(font);
        helpText.setString("2. Help");
        helpText.setCharacterSize(24);
        helpText.setFillColor(sf::Color::Red);
        helpText.setStyle(sf::Text::Bold);
        helpText.setPosition(280, 240);

        sf::Text inventoryText;
        inventoryText.setFont(font);
        inventoryText.setString("3. Display Inventory");
        inventoryText.setCharacterSize(24);
        inventoryText.setFillColor(sf::Color::Red);
        inventoryText.setStyle(sf::Text::Bold);
        inventoryText.setPosition(280, 280);

        sf::Text exitText;
        exitText.setFont(font);
        exitText.setString("4. Exit");
        exitText.setCharacterSize(24);
        exitText.setFillColor(sf::Color::Red);
        exitText.setStyle(sf::Text::Bold);
        exitText.setPosition(280, 320);

        // Create rectangles for clickable areas
        sf::RectangleShape startButton(sf::Vector2f(200, 40));
        startButton.setFillColor(sf::Color::Transparent);
        startButton.setPosition(280, 200);

        sf::RectangleShape helpButton(sf::Vector2f(200, 40));
        helpButton.setFillColor(sf::Color::Transparent);
        helpButton.setPosition(260, 240);

        sf::RectangleShape inventoryButton(sf::Vector2f(200, 40));
        inventoryButton.setFillColor(sf::Color::Transparent);
        inventoryButton.setPosition(220, 280);

        sf::RectangleShape exitButton(sf::Vector2f(200, 40));
        exitButton.setFillColor(sf::Color::Transparent);
        exitButton.setPosition(280, 320);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                // Check for button clicks
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // Get mouse position
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // Check if any button is clicked
                        if (startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            // Call start game function
                            startGame();
                        } else if (helpButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            // Call help function
                            displayHelp();
                        } else if (inventoryButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            // Call display inventory function
                            inventoryShow();
                        } else if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            // Close the window
                            window.close();
                        }
                    }
                }
            }

            // Clear the window
            window.clear();

            // Draw background
            window.draw(backgroundSprite);

            // Draw menu items
            window.draw(startText);
            window.draw(helpText);
            window.draw(inventoryText);
            window.draw(exitText);

            // Display everything
            window.display();
        }
    }

private:
    // Function to start the game
   
    // Function to display help
    void displayHelp() {
       displayGameInstructions();
    }

    // Function to display inventory
    void inventoryShow() {
        t.insertFromFile("item.text");
       // cout<<"calling display";
        t.display();
       // tree.displayInventory();
    }

    void startGame()
    {
       
       rungame();
    }
};

#endif // GAME_MENU_H
