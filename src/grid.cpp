//This file contains the functions to draw the grid and the cells of the grid
//The functions are used to draw the grid and the cells of the grid
//This file contains the functions to draw the grid and the cells of the grid

#include "raylib.h"
#include <iostream>
#include <vector> 
#include <cstdlib> 
#include <ctime> 


void drawCell(int x, int y, int value)
{
    Color color_off_white = {245, 245, 220, 255};
    Color color_red_japon = {206, 43, 55, 255};
    Color color = (value == 1) ? color_red_japon : color_off_white;
    DrawRectangle(x, y, 19, 19, color);
}

void drawGrid(const std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < 1600; i += 20)
    {
        DrawLine(i, 0, i, 1600, GRAY);
        DrawLine(0, i, 1600, i, GRAY);

        for (int j = 0; j < 1600; j += 20)
        {
            if (j / 20 < matrix.size() && i / 20 < matrix[j / 20].size())
            {
                drawCell(i, j, matrix[j / 20][i / 20]);
            }
        }
    }
}

