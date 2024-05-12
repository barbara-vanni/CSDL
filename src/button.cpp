#include "raylib.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "hpp_file/selectGame.hpp"
#include "hpp_file/pause.hpp"
#include "hpp_file/eraser.hpp"


void drawInstructions()
{
    int fontSize = 25; 
    int lineHeight = fontSize + 10; 

    int startY = (800 + 1000 - (lineHeight * 4)) / 2;

    DrawText("Press S to Save", (GetScreenWidth() - MeasureText("Press S to Save", fontSize)) / 2, startY, fontSize, WHITE);
    DrawText("Press P to Pause", (GetScreenWidth() - MeasureText("Press P to Pause", fontSize)) / 2, startY + lineHeight, fontSize, WHITE);
    DrawText("Press Escap to go back to Menu", (GetScreenWidth() - MeasureText("Press Escap to go back to Menu", fontSize)) / 2, startY + 2 * lineHeight, fontSize, WHITE);
    DrawText("Press K to quit", (GetScreenWidth() - MeasureText("Press K to quit", fontSize)) / 2, startY + 3 * lineHeight, fontSize, WHITE);
}


void drawButtons()
{
    drawInstructions(); 

    if (IsKeyPressed(KEY_S))
    {
        std::cout << "Save" << std::endl;
        // displayGameSave();
        // std::vector<std::vector<int>> matrix; 
        // fillMatrix(matrix);
        fillMatrix();
        saveMatrixToFile("src/txt_file/save.txt");
    }
    else if (IsKeyPressed(KEY_P))
    {
        std::cout << "Pause" << std::endl;
        pauseGame();
    }
    else if (IsKeyPressed(KEY_K))
    {
        std::cout << "Quit" << std::endl;
        CloseWindow();
    }
    else if (IsKeyPressed(KEY_M))
    {
        std::cout << "Menu" << std::endl;
    }
}