#include "GameWindow.h"
#include "/Users/apple/Downloads/sfml-macos/src/menu.h"
#include"/Users/apple/Downloads/sfml-macos/src/menu.h"
#include"/Users/apple/Downloads/sfml-macos/src/generateMaze.h"



int main() {
    // Create a window for the game
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Window");
    window.setFramerateLimit(60);
    runGameWindow();

      GameMenu menu;
      menu.display();
      return 0;

}
