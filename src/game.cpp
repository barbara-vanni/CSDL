//This file contains the functions that are used to draw the buttons on the screen and the instructions to play the game.
//The functions are used to draw the buttons on the screen and the instructions to play the game.


#include "raylib.h"
#include <iostream>
#include <vector> 
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <sstream>
#include "hpp_file/grid.hpp"
#include "hpp_file/button.hpp"
#include "hpp_file/alive.hpp"


extern std::vector<std::vector<int>> matrix;


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
    
    std::vector<std::vector<int>> newMatrix = matrix;


    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            int livingNeighbors = alive(matrix, i, j);

            if (matrix[i][j] == 1)
            {
                if (livingNeighbors < 2 || livingNeighbors > 3)
                {
                    newMatrix[i][j] = 0;
                }
            }
            else
            {
                if (livingNeighbors == 3)
                {
                    newMatrix[i][j] = 1;
                }
            }
        }
    }

    matrix = newMatrix;
}



void displayGame()
{
    std::vector<std::vector<int>> matrix = readMatrixFromFile("src/txt_file/matrix0.txt");

    while (true) 
    {
        if (WindowShouldClose())
        {
            break;
        }

        updateMatrix(matrix);

        BeginDrawing();

        ClearBackground(BLACK);

        BeginScissorMode(0, 0, GetScreenWidth(), 800);
        drawGrid(matrix);
        EndScissorMode();

        BeginScissorMode(0, 800, GetScreenWidth(), GetScreenHeight() - 200);
        drawButtons(matrix);
        EndScissorMode();

        EndDrawing(); 
    }
}
