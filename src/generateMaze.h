
#ifndef GENERATEMAZE_H
#define GENERATEMAZE_H

#include <SFML/Graphics.hpp>

#include"Gameend.h"
#include"HandleCollision.h"
#include"ResetGame.h"
#include"Exitgame.h"
#include"Inventorymanagment.h"
#include"item.txt"
#include"ScoreRead.h"
#include"menu.h"

#include <iostream>
#include <cmath>
using namespace std;


sf::Font font;

void rungame() {
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "GamePlay");
    std::srand(std::sin(std::time(nullptr)) * 1000);
    int frameCount = 0;
    int moveTimer = 1000;

    bool updatePath = true;
    int orderedSet [15 * 15];
    int path [100];
    int pathSize = 0;
    int pathPos = 0;

    sf::Vector2i player = sf::Vector2i(13, 13);
    sf::Texture playerTex;
    playerTex.loadFromFile("/Users/apple/Downloads/sfml-macos/src/playerFinal (1).png");
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTex);
    playerSprite.setPosition(player.x * 40.f, player.y * 40.f);

    sf::Vector2i opponent = sf::Vector2i(1, 1);
    sf::Texture opponentTex;
    opponentTex.loadFromFile("/Users/apple/Downloads/sfml-macos/src/enemy.png");
    sf::Sprite opponentSprite;
    opponentSprite.setTexture(opponentTex);
    opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);

    sf::Vector2i opponent2 = sf::Vector2i(2, 2); // Different initial position
    sf::Texture opponentTex2;
    opponentTex2.loadFromFile("/Users/apple/Downloads/sfml-macos/src/enemy.png"); // Load texture
    sf::Sprite opponentSprite2;
    opponentSprite2.setTexture(opponentTex2);
    opponentSprite2.setPosition(opponent2.x * 40.f, opponent2.y * 40.f);

    sf::Texture coinTex;
    coinTex.loadFromFile("/Users/apple/Downloads/sfml-macos/src/Fruits (1) copy.png");
    sf::Sprite coins [5];
    int numCoins = 0;
    int score = 0;


    sf::Texture ArtifactTex;
    ArtifactTex.loadFromFile("/Users/apple/Downloads/sfml-macos/src/artifact-removebg-preview (2).png"); 
     sf::Sprite artifact [5];
    int numAritfact=0;

    sf::Texture SwordTex;
    SwordTex.loadFromFile("/Users/apple/Downloads/sfml-macos/src/sword_35x35-removebg-preview.png");
    sf::Sprite sword [5];
    int numsword=0;

     sf::Texture FireTex;
     FireTex.loadFromFile("/Users/apple/Downloads/sfml-macos/src/fire (2).png");
     sf::Sprite fireSprite [5];
     int numfire=0;

      sf::Texture heartTexture;
      heartTexture.loadFromFile("/Users/apple/Downloads/sfml-macos/src/life (1).png");
      sf::Sprite heartSprite;
      heartSprite.setTexture(heartTexture);
  
      float heartWidth = static_cast<float>(heartTexture.getSize().x);
      float gap = 2.0f;
      float initialX = 700.f;
      float y = 200.f;
      int numHearts = 3;   

    sf::Texture exitTex;
    exitTex.loadFromFile("/Users/apple/Downloads/sfml-macos/src/download (1).png"); 
    sf::Sprite exit;
    exit.setTexture(exitTex);
    exit.setPosition(25,30);

    int gameMap [15 * 15];
    sf::RectangleShape displayRects [15 * 15];
    sf::Font font;
    font.loadFromFile("/Users/apple/Downloads/sfml-macos/Roboto/Roboto-Bold.ttf");
    sf::Text text2;
    text2.setFont(font);
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Blue);
    text2.setString("Lives: "); // Display the remaining number of hearts
    text2.setPosition(630.f,150.f);

  

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10); // Adjust position as needed


//setting the maze grids
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            displayRects[i + j * 15].setPosition(i * 40.f, j * 40.f);
            displayRects[i + j * 15].setSize(sf::Vector2f(40.f, 40.f));
            displayRects[i + j * 15].setOutlineThickness(1.f);
            displayRects[i + j * 15].setOutlineColor(sf::Color(1, 1, 1));

            if(!(i == opponent.x && j == opponent.y) && !(i == player.x && j == player.y)){
                if(std::rand()/ (float) RAND_MAX < 0.22f || i == 0 || j == 0 || i == 14 || j == 14) {
                    gameMap[i + j * 15] = 1;
                    displayRects[i + j * 15].setFillColor(sf::Color(255, 0,0));
                }
            }
        }
    }

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::KeyPressed) {
                switch(event.key.code){
                    case sf::Keyboard::Up:
                        if(gameMap[player.x + (player.y - 1) * 15] != 1) player.y -= 1;
                        break;
                    case sf::Keyboard::Down:
                        if(gameMap[player.x + (player.y + 1) * 15] != 1) player.y += 1;
                        break;
                    case sf::Keyboard::Right:
                        if(gameMap[(player.x + 1) + player.y * 15] != 1) player.x += 1;
                        break;
                    case sf::Keyboard::Left:
                        if(gameMap[(player.x - 1) + player.y * 15] != 1) player.x -= 1;
                        break;
                }
            }

            updatePath = true;
            pathSize = 0;
            pathPos = 0;
            playerSprite.setPosition(player.x * 40.f, player.y * 40.f);
        }
    
          while(numCoins < 3) {
            int col = (std::rand() / (float) RAND_MAX) * 15.f;
            int row = (std::rand() / (float) RAND_MAX) * 15.f;

            if(gameMap[col + row * 15] == 0) {
                gameMap[col + row * 15] = 2;
                coins[numCoins].setTexture(coinTex);
                coins[numCoins].setPosition(col*40.f,row*40.f);
                numCoins += 1;
            }
        }
          while(numAritfact<3)
          {
             int col = (std::rand() / (float) RAND_MAX) * 15.f;
            int row = (std::rand() / (float) RAND_MAX) * 15.f;

            if(gameMap[col + row * 15] == 0) {
                gameMap[col + row * 15] = 3;
                artifact[numAritfact].setTexture(ArtifactTex);
                numAritfact[artifact].setPosition(col*40.f,row*40.f);
                numAritfact +=1;
              }
          }
          while(numsword<3)
          {
             int col = (std::rand() / (float) RAND_MAX) * 15.f;
            int row = (std::rand() / (float) RAND_MAX) * 15.f;

            if(gameMap[col + row * 15] == 0) {
                gameMap[col + row * 15] = 4;
                sword[numsword].setTexture(SwordTex);
                //coins[numCoins].setPosition(col * 40.f, row * 40.f);
                numsword[sword].setPosition(col*40.f,row*40.f);
                numsword +=1;
                 }
          }

          while(numfire<4)
          {
            int col = (std::rand() / (float) RAND_MAX) * 15.f;
            int row = (std::rand() / (float) RAND_MAX) * 15.f;
              if(gameMap[col + row * 15] == 0) {
                gameMap[col + row * 15] = 5;
                fireSprite[numfire].setTexture(FireTex);
                //coins[numCoins].setPosition(col * 40.f, row * 40.f);
                numfire[fireSprite].setPosition(col*40.f,row*40.f);
                numfire +=1;
          
          }
          }
    window.clear(sf::Color(255, 255, 255));

        for(int i = 0; i < 15 * 15; i++) {
            window.draw(displayRects[i]);
        }
          
        for(int i = 0; i < numCoins; i++) {
            window.draw(coins[i]);
        }
       
        for(int i = 0; i < numAritfact; i++) {
            window.draw(artifact[i]);
        }
         for(int i = 0; i < numsword; i++) {
            window.draw(sword[i]);
        }

        for(int i=0; i<numfire;i++)
        {
            window.draw(fireSprite[i]);
        }
        
       if(updatePath == true) {
            int counter = 0;

            int fullSet [2000];
            int fullSetSize = 0;

            int openSet [100];
            int openSetSize = 2;
            openSet[0] = player.x + player.y * 15;
            openSet[1] = counter;

            int currentIndex = player.x + player.y * 15;

            while(currentIndex != opponent.x + opponent.y * 15) {
                currentIndex = openSet[0];
                counter = openSet[1] + 1;
                int neighbors [4];

                neighbors[0] = currentIndex - 1;
                neighbors[1] = currentIndex + 1;
                neighbors[2] = currentIndex - 15;
                neighbors[3] = currentIndex + 15;

                for(int i = 0; i < 8; i += 2) {
                    bool alreadyExists = false;

                    for(int j = 0; j < fullSetSize; j += 2) {
                        if(neighbors[i/2] == fullSet[j]) {
                            alreadyExists = true;
                            break;
                        }
                    }

                    if(alreadyExists == false) {
                        if(gameMap[neighbors[i/2]] != 1) {
                            fullSet[fullSetSize] = neighbors[i/2];
                            fullSet[fullSetSize + 1] = counter;
                            fullSetSize += 2;

                            openSet[openSetSize] = neighbors[i/2];
                            openSet[openSetSize + 1] = counter;
                            openSetSize += 2;
                        } else {
                            fullSet[fullSetSize] = neighbors[i/2];
                            fullSet[fullSetSize + 1] = 100000;
                            fullSetSize += 2;
                        }
                    }
                }

                for(int i = 0; i < openSetSize; i++) {
                    openSet[i] = openSet[i + 2];
                }

                openSetSize -= 2;
            }

            for(int i = 0; i < 15 * 15; i++) {
                orderedSet[i] = 100000;
            }

            for(int i = 0; i < fullSetSize; i += 2) {
                orderedSet[fullSet[i]] = fullSet[i + 1];
            }

            orderedSet[player.x + player.y * 15] = 0;

            int pathIndex = opponent.x + opponent.y * 15;

            while(pathIndex != player.x + player.y * 15) {
                int neighbors [4];

                neighbors[0] = pathIndex - 1;
                neighbors[1] = pathIndex + 1;
                neighbors[2] = pathIndex - 15;
                neighbors[3] = pathIndex + 15;

                int lowest [2] ={0, 100000};
                for(int i = 0; i < 4; i++) {
                    if(orderedSet[neighbors[i]] < lowest[1]) {
                        lowest[0] = i;
                        lowest[1] = orderedSet[neighbors[i]];
                    }
                }

                pathIndex = neighbors[lowest[0]];

                path[pathSize] = pathIndex;

                pathSize += 1;
            }

            updatePath = false;
        }

        if(frameCount % moveTimer == 0) {
            opponent.x = path[pathPos] % 15;
            opponent.y = std::floor(path[pathPos]/15);
            opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);
            pathPos += 1;

            if(moveTimer >= 250) {
                moveTimer = 1000 - std::floor(frameCount/1000) * 4;
            }
        }
        window.draw(playerSprite);
        window.draw(opponentSprite);
        window.draw(text2);
        window.draw(exit);
      
        for (int i = 0; i < numHearts; ++i) {
        float xPos = initialX + (heartWidth + gap) * i;
        heartSprite.setPosition(xPos, y);
        window.draw(heartSprite);
}
        
        window.display();

        if(gameMap[player.x + player.y * 15] == 2) 
        {
            gameMap[player.x + player.y * 15] = 0;
         handleCollisionWithCoin(player.x, player.y, numCoins, coins, score, playerSprite);
       
       // writeFile("item.txt",10,"Enchanted Fruit");
        }
        updatePlayerColor(playerSprite);
       
        if(gameMap[player.x + player.y * 15] == 3) 
           {
            gameMap[player.x + player.y * 15] = 0;
             artifactCollision(player.x, player.y, numAritfact, artifact, score, playerSprite);
         //  writeFile("item.txt",15,"Ancient Flask");
            }
            updatePlayerColor(playerSprite);

            if(gameMap[player.x + player.y * 15] == 4) 
             {
            gameMap[player.x + player.y * 15] = 0;
            collision(player.x, player.y, numsword, sword, score, playerSprite);
          //  writeFile("item.txt",20,"Magical Sword");
             }
            updatePlayerColor(playerSprite);


            if(gameMap[player.x + player.y * 15] == 5)
            {
                gameMap[player.x + player.y * 15] = 0;
                Firecollision(player.x, player.y, numfire, fireSprite, score, playerSprite);
              //writeFile("item.txt",25,"Fire Ball");
            }
          
          if(player.x==1 && player.y ==1)   //game winning postion 
           {
            window.close();
            exitGame();
           }

        frameCount+=1;

    if (player == opponent) { 


    if(playerHasSword) 
    {
        swordcount--;
        opponent.x = 1; // Restore opponent's x position to its original value
        opponent.y = 1; // Restore opponent's y position to its original value
        opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);
    } else
    {
      if (numHearts > 1) {
            // Reset the game state
            resetGameState(playerSprite, opponentSprite, player, opponent);
            numHearts--;
            
            // Clear the window and redraw game elements
            window.clear(sf::Color(255, 255, 255));
            for (int i = 0; i < 15 * 15; i++) {
                window.draw(displayRects[i]);
            }
            window.draw(playerSprite);
            window.draw(opponentSprite);
            // Continue the game loop
            window.display();
           
            continue;
           } 
        else {
            // End the game if numHearts is 0
            window.close();
            showGameOver();
            displayStats(score);
            break; // Exit the game loop
        }
         
    }
    
}
    }
    }

#endif