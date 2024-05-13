//This file contains the function that displays the main menu of the game.
//The function is called in the main.cpp file.
//The function is used to display the main menu of the game.

#include "raylib.h"
#include <iostream>

void displayMenu()
{
    ClearBackground(BLACK);

    const char* welcomeText1 = "Welcome to the ";
    const char* welcomeText2 = "Game of Life!";
    const char* startText = "Press Enter to start the game.";

    int fontSize1 = 140;
    int fontSize2 = 40;

    int welcomeWidth1 = MeasureText(welcomeText1, fontSize1);
    int welcomeWidth2 = MeasureText(welcomeText2, fontSize1);
    int startWidth = MeasureText(startText, fontSize2);

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int welcomeX1 = (screenWidth - welcomeWidth1) / 2;
    int welcomeX2 = (screenWidth - welcomeWidth2) / 2;
    int startX = (screenWidth - startWidth) / 2;
    int textY = screenHeight / 2 - fontSize1;

    DrawText(welcomeText1, welcomeX1, textY, fontSize1, WHITE);
    DrawText(welcomeText2, welcomeX2, textY + fontSize1, fontSize1, WHITE);
    DrawText(startText, startX, (textY + 2 * fontSize1) + 100, fontSize2, WHITE);

    EndDrawing();
}
