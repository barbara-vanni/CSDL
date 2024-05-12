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


std::vector<std::vector<int>> readMatrixRandomFile(const std::string& filename)
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

void randomMatrix(std::vector<std::vector<int>>& matrix, int maxOnes)
{
    srand(time(0));

    int countOnes = 0; 

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (countOnes < maxOnes)
            {
                matrix[i][j] = rand() % 2;
                if (matrix[i][j] == 1)
                {
                    ++countOnes;  
                }
            }
            else
            {
                matrix[i][j] = 0;  
            }
        }
    }
}



void updateMatrixRandom(std::vector<std::vector<int>>& matrix)
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


void displayRandomGame()
{
    std::vector<std::vector<int>> matrix = readMatrixRandomFile("src/txt_file/matrix_vierge.txt");
    randomMatrix(matrix, 2600);

    while (true) 
    {
        if (WindowShouldClose())
        {
            break;
        }

        updateMatrixRandom(matrix);

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
