#include "raylib.h"
#include "hpp_file/game.hpp"
#include "hpp_file/random.hpp"
#include "hpp_file/save.hpp"
#include "hpp_file/pattern1.hpp"
#include "hpp_file/pattern2.hpp"
#include "hpp_file/pattern3.hpp"
#include <iostream>

// Display the select game screen where we can choose wich file to play


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
                    displayRandomGame();
                }
                else if (i == 2)
                {
                    displayGameSave();
                }
                else if (i == 3)
                {
                    displayGamePattern1();
                    // displayGame();
                }
                else if (i == 4)
                {
                    displayGamePattern2();
                    // displayGame();
                }
                else if (i == 5)
                {
                    displayGamePattern3();
                    // displayGame();
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
