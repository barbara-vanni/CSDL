#include "raylib.h"
#include "game.hpp"
#include <iostream>


void displaySelectGame()
{
    ClearBackground(BLACK);

    DrawText("Select your game", GetScreenWidth() / 2 - MeasureText("Select your game", 60) / 2, 100, 60, WHITE);

    const char* gameText[] = {"Standard", "Random", "Continue", "Pattern 1", "Pattern 2", "Pattern 3"};
    const int numGames = sizeof(gameText) / sizeof(gameText[0]);
    const int rectWidth = 400;
    const int rectHeight = 100;
    const int textSize = 40;

    int xPos = 200;
    int yPos = 250;

    for (int i = 0; i < numGames; ++i)
    {
        if (CheckCollisionPointRec(GetMousePosition(), { (float)xPos, (float)yPos, (float)rectWidth, (float)rectHeight }))
        {
            DrawRectangle(xPos, yPos, rectWidth, rectHeight, RED);

            int textXPos = xPos + (rectWidth - MeasureText(gameText[i], textSize)) / 2;
            int textYPos = yPos + (rectHeight - textSize) / 2;
            DrawText(gameText[i], textXPos, textYPos, textSize, BLACK);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (i == 0)
                {
                    displayGame();
                }
                else if (i == 1)
                {
                    displayGame();
                }
                else if (i == 2)
                {
                    displayGame();
                }
                else if (i == 3)
                {
                    displayGame();
                }
                else if (i == 4)
                {
                    displayGame();
                }
                else if (i == 5)
                {
                    displayGame();
                }

            }
        }
        else
        {
            DrawRectangle(xPos, yPos, rectWidth, rectHeight, WHITE);
            int textXPos = xPos + (rectWidth - MeasureText(gameText[i], textSize)) / 2;
            int textYPos = yPos + (rectHeight - textSize) / 2;
            DrawText(gameText[i], textXPos, textYPos, textSize, BLACK);
        }
        if (i % 2 == 0)
        {
            xPos += 800;
        }
        else
        {
            xPos = 200;
            yPos += 250;
        }
    }
    EndDrawing();
}
