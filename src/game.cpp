#include "raylib.h"
#include <iostream>
#include <vector> 
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <sstream>

extern std::vector<std::vector<int>> matrix;

int alive(const std::vector<std::vector<int>>& matrix, int row, int col);
void drawButtons();
void drawGrid(const std::vector<std::vector<int>>& matrix);

std::vector<std::vector<int>> readMatrixFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<std::vector<int>> matrix;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::vector<int> row;
            std::istringstream iss(line);
            int value;
            while (iss >> value)
            {
                row.push_back(value);
            }
            matrix.push_back(row);
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return matrix;
}

void updateMatrix(std::vector<std::vector<int>>& matrix)
{
    
    // Créer une copie de la matrice pour stocker les mises à jour
    std::vector<std::vector<int>> newMatrix = matrix;


    // Parcourir chaque cellule de la matrice
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            // Compter le nombre de voisins vivants
            int livingNeighbors = alive(matrix, i, j);

            // Appliquer les règles du jeu de la vie
            if (matrix[i][j] == 1)
            {
                if (livingNeighbors < 2 || livingNeighbors > 3)
                {
                    // Toute cellule vivante avec moins de 2 ou plus de 3 voisins vivants meurt
                    newMatrix[i][j] = 0;
                }
            }
            else
            {
                if (livingNeighbors == 3)
                {
                    // Toute cellule morte avec exactement 3 voisins vivants devient vivante
                    newMatrix[i][j] = 1;
                }
            }
        }
    }

    // Mettre à jour la matrice originale avec les mises à jour
    matrix = newMatrix;
}




void displayGame()
{
    // int iterations = 0;
    while (true) // Boucle infinie
    {
        if (WindowShouldClose())
        {
            break; // Sortir de la boucle si la fenêtre est fermée
        }

        BeginDrawing();

        ClearBackground(BLACK);

        std::vector<std::vector<int>> matrix = readMatrixFromFile("src/matrix.txt");
        // std::cout << "Iteration: " << iterations << std::endl;
        // iterations++; 

        // Mettre à jour la matrice avec les nouvelles données
        updateMatrix(matrix);

        BeginScissorMode(0, 0, GetScreenWidth(), 400);
        drawGrid(matrix);
        EndScissorMode();

        BeginScissorMode(0, 400, GetScreenWidth(), GetScreenHeight() - 400);
        drawButtons();
        EndScissorMode();

        EndDrawing();
    }
}
