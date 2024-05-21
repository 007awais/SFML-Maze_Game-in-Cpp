#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

// Include necessary libraries
#include <iostream>

// Define infinity value
const int INF = 100000;

// Function prototype for finding the shortest path
// Function implementatio
void findShortestPath(int playerX, int playerY, int opponentX, int opponentY, int gameMap[][15], int distance[][15]) 
{
    // Initialize visited array to keep track of visited nodes
    bool visited[15][15] = {false};

    // Set initial distances
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            distance[i][j] = INF;
        }
    }
    distance[playerX][playerY] = 0;

    // Loop until all reachable nodes are visited
    while (true) {
        // Find the node with the minimum distance among unvisited nodes
        int minDist = INF;
        int minX = -1, minY = -1;
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                if (!visited[i][j] && distance[i][j] < minDist) {
                    minDist = distance[i][j];
                    minX = i;
                    minY = j;
                }
            }
        }

        // If no unvisited nodes left or the opponent is reached, break
        if (minDist == INF || (minX == opponentX && minY == opponentY)) {
            break;
        }

        // Mark the node as visited
        visited[minX][minY] = true;

        // Update distances of neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = minX + dx;
                int ny = minY + dy;

                // Check if neighbor is within bounds and not a wall
                if (nx >= 0 && nx < 15 && ny >= 0 && ny < 15 && gameMap[nx][ny] != 1) {
                    // Calculate new distance
                    int newDist = distance[minX][minY] + 1;

                    // Update distance if shorter path found
                    if (newDist < distance[nx][ny]) {
                        distance[nx][ny] = newDist;
                    }
                }
            }
        }
    }
}

#endif // SHORTESTPATH_H
