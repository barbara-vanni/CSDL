// grid.cpp
#include "raylib.h"
#include "grid.h"
#include <iostream>

// Définition des variables
std::vector<std::vector<int>> matrix;

// Définition des fonctions
void drawCell(int x, int y, const std::vector<std::vector<int>>& matrix)
{
    int cellSize = 20;
    if (matrix[y / cellSize][x / cellSize] == 1)
    {
        DrawRectangle(x, y, cellSize, cellSize, WHITE);
    }
}

void drawGrid()
{

    const int gridSize = static_cast<int>(matrix.size());
    const int cellSize = 20;

    for (std::vector<std::vector<int>>::size_type i = 0; i < gridSize; ++i)
    {
        for (std::vector<int>::size_type j = 0; j < gridSize; ++j)
        {
            int x = static_cast<int>(j * cellSize);
            int y = static_cast<int>(i * cellSize);
            drawCell(x, y, matrix);
        }
    }

    for (std::vector<std::vector<int>>::size_type i = 0; i <= gridSize; ++i)
    {
        DrawLine(static_cast<int>(i * cellSize), 0, static_cast<int>(i * cellSize), static_cast<int>(gridSize * cellSize), GRAY);
        DrawLine(0, static_cast<int>(i * cellSize), static_cast<int>(gridSize * cellSize), static_cast<int>(i * cellSize), GRAY);
    }
}
