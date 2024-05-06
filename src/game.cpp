#include "raylib.h"
#include <iostream>
#include <vector> 
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <sstream>

extern std::vector<std::vector<int>> matrix;

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

void displayGame()
{
    BeginDrawing();

    ClearBackground(BLACK);

    
    std::vector<std::vector<int>> matrix = readMatrixFromFile("src/matrix.txt");

    BeginScissorMode(0, 0, GetScreenWidth(), 400);
    drawGrid(matrix);
    EndScissorMode();

    BeginScissorMode(0, 400, GetScreenWidth(), GetScreenHeight() - 400);
    drawButtons();
    EndScissorMode();

    EndDrawing();
}

