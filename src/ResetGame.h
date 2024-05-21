#include<iostream>
#include<SFML/Graphics.hpp>
#include"/Users/apple/Downloads/sfml-macos/src/generateMaze.h"
using namespace std;


void resetGameState(sf::Sprite& playerSprite, sf::Sprite& opponentSprite, sf::Vector2i& player, sf::Vector2i& opponent) {
    // Reset player and opponent positions to their initial positions
    player = sf::Vector2i(13, 13);
    opponent = sf::Vector2i(1, 1);
    
    // Reset their sprites' positions accordingly
    playerSprite.setPosition(player.x * 40.f, player.y * 40.f);
    opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);
    cout<<"hellllo";
    // Reset other game state variables
   
}
