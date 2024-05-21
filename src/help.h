#include <SFML/Graphics.hpp>

void displayGameInstructions() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Instructions");
    
    // Load background texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/apple/Downloads/sfml-macos/src/help_background.jpeg")) {
        // Handle error if background image fails to load
        return;
    }
    sf::Sprite backgroundSprite(backgroundTexture);
    
    // Scale the background sprite to cover the whole window
    backgroundSprite.setScale(static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
                              static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y);
    
    // Create font for text
    sf::Font font;
    if (!font.loadFromFile("/Users/apple/Downloads/sfml-macos/Roboto/Roboto-Bold.ttf")) {
        // Handle error if font fails to load
        return;
    }
    
    // Create text object
    sf::Text instructionText;
    instructionText.setFont(font);
    instructionText.setCharacterSize(24);
    instructionText.setFillColor(sf::Color::Red);
    instructionText.setString("Welcome to the game!\n\n"
                               "Instructions:\n"
                               "- Use arrow keys to move\n"
                               "- Collect fruits to score points\n"
                               "- Collect the hidden treasure to score bonus\n"
                               "- Capture the Sword to face the enemy\n"
                               "- Reach the Green zone to get exit the maze\n"
                               "- Avoid enemies\n\n"
                               "Press 'Esc' to exit");
    instructionText.setPosition(290.f, 150.f);
    
    


    // Main loop to display the window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
        
        // Clear the window
        window.clear();
        
        // Draw the background and text
        window.draw(backgroundSprite);
        window.draw(instructionText);
        
        // Display everything
        window.display();
    }
}
