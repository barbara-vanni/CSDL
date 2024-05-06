#include "raylib.h"
#include <iostream>
#include <vector> 
#include <cstdlib> 
#include <ctime> 

void drawCell(int x, int y, int value);

void drawGrid(const std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < 800; i += 20)
    {
        DrawLine(i, 0, i, 800, GRAY);
        DrawLine(0, i, 800, i, GRAY);

        for (int j = 0; j < 800; j += 20)
        {
            if (j / 20 < matrix.size() && i / 20 < matrix[j / 20].size())
            {
                drawCell(i, j, matrix[j / 20][i / 20]);
            }
            else
            {
                // Gérer les cas où les indices sont en dehors des limites de la matrice
                // Par exemple, ignorer ou afficher un message d'erreur
            }
        }
    }
}

void drawCell(int x, int y, int value)
{
    Color color = (value == 1) ? RED : BLACK;
    DrawRectangle(x, y, 19, 19, color);
}
