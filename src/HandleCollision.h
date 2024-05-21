#ifndef COLLISION_HANDLING_H
#define COLLISION_HANDLING_H

#include<SFML/Graphics.hpp>
#include"/Users/apple/Downloads/sfml-macos/src/generateMaze.h"
#include <iostream>
#include <cmath>
#include <SFML/Audio.hpp>
using namespace std;


// Define original and alternate player colors
sf::Color originalColor = sf::Color::Yellow;
//sf::Color alternateColor = sf::Color::Green;

// Define a clock for timing
sf::Clock colorChangeClock;
sf::Time colorChangeDuration = sf::seconds(0.1f); // Change color for 1 second

// Function to handle collision detection


void handleCollisionWithCoin(int playerX, int playerY, int& numCoins, sf::Sprite coins[], int& score, sf::Sprite& playerSprite) {
    // Load the sound buffer
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("/Users/apple/Downloads/sfml-macos/src/so-slimy-46602.wav")) {
        std::cerr << "Failed to load sound!" << std::endl;
        return; // Return if sound loading fails
    }

   sf::Sound sound;
    sound.setBuffer(buffer);
     for(int i = 0; i < numCoins; i++) {
        if(coins[i].getPosition().x / 40 == playerX && coins[i].getPosition().y / 40 == playerY) {
            
            if (i != numCoins - 1) {
                std::swap(coins[i], coins[numCoins - 1]);
            }

            
            numCoins -= 1;
            score += 1;
            sound.play();

            
            playerSprite.setColor(sf::Color(0, 255, 0));
            colorChangeClock.restart();

            break; // No need to continue checking for collisions after handling one
        }
    }
}
bool playerHasSword=false;
bool oponentSpawned= false;
int swordcount=0;

void artifactCollision(int playerX, int playerY, int& numArtifact, sf::Sprite artifact[], int& score, sf::Sprite& playerSprite)
{
    for(int i = 0; i < numArtifact; i++) {
        if(artifact[i].getPosition().x / 40 == playerX && artifact[i].getPosition().y / 40 == playerY) {
            // Player collided with a coin

            // Move the coin sprite to the end of the array
            if (i != numArtifact - 1) {
                std::swap(artifact[i], artifact[numArtifact - 1]);
            }

            // Decrease the number of coins
            numArtifact -= 1;
            // Updating the score variable
            score += 5;
           

// Change player color
            playerSprite.setColor(sf::Color(0, 255, 0));
            colorChangeClock.restart();

            break; // No need to continue checking for collisions after handling one
        }
    }
   
    
}

void collision(int playerX, int playerY, int& numsword, sf::Sprite sword[], int& score, sf::Sprite& playerSprite)
{
for(int i = 0; i < numsword; i++) {
        if(sword[i].getPosition().x / 40 == playerX && sword[i].getPosition().y / 40 == playerY) {
            // Player collided with a coin

            // Move the coin sprite to the end of the array
            if (i != numsword - 1) {
                std::swap(sword[i], sword[numsword - 1]);
            }

            // Decrease the number of coins
            numsword=-1;

            // Updating the score variable
            score += 5;
          

            // Change player color
            playerSprite.setColor(sf::Color(0, 255, 0));
            colorChangeClock.restart();

            break; // No need to continue checking for collisions after handling one
        }
    }
}


void Firecollision(int playerX, int playerY, int& numfire, sf::Sprite firesprite[], int& score, sf::Sprite& playerSprite)
{
   for(int i = 0; i < numfire; i++) {
        if(firesprite[i].getPosition().x / 40 == playerX && firesprite[i].getPosition().y / 40 == playerY) {
            // Player collided with a coin

            // Move the coin sprite to the end of the array
            if (i != numfire - 1) {
                std::swap(firesprite[i], firesprite[numfire - 1]);
            }

            // Decrease the number of coins
            numfire=-1;

            // Updating the score variable
            score += 5;
           

            // Change player color
            playerSprite.setColor(sf::Color(0, 255, 0));
            colorChangeClock.restart();

            break; // No need to continue checking for collisions after handling one
        }
    }
}


void updatePlayerColor(sf::Sprite& playerSprite) {
    if (colorChangeClock.getElapsedTime() >= colorChangeDuration) {
        playerSprite.setColor(originalColor);
    }
}

#endif // COLLISION_HANDLING_H
