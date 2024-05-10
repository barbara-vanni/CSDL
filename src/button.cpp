#include "raylib.h"
#include <iostream>
#include "hpp_file/selectGame.hpp"

void drawButtons()
{
    int buttonWidth = 300;
    int buttonHeight = 50;
    int buttonSpacing = 50;
    int totalWidth = 4 * buttonWidth + 3 * buttonSpacing;
    int startX = (GetScreenWidth() - totalWidth) / 2;
    int startY = GetScreenHeight() - 150;

    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    Rectangle button1 = {startX, startY, buttonWidth, buttonHeight};
    Rectangle button2 = {startX + buttonWidth + buttonSpacing, startY, buttonWidth, buttonHeight};
    Rectangle button3 = {startX + 2 * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight};
    Rectangle button4 = {startX + 3 * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight};

    Color buttonColor1 = (CheckCollisionPointRec({(float)mouseX, (float)mouseY}, button1)) ? RED : WHITE;
    Color buttonColor2 = (CheckCollisionPointRec({(float)mouseX, (float)mouseY}, button2)) ? RED : WHITE;
    Color buttonColor3 = (CheckCollisionPointRec({(float)mouseX, (float)mouseY}, button3)) ? RED : WHITE;
    Color buttonColor4 = (CheckCollisionPointRec({(float)mouseX, (float)mouseY}, button4)) ? RED : WHITE;

    DrawRectangleRec(button1, buttonColor1);
    DrawText("SAVE", button1.x + buttonWidth/2 - MeasureText("SAVE", 50)/2, button1.y + (buttonHeight - 50)/2, 50, BLACK);
    
    DrawRectangleRec(button2, buttonColor2);
    DrawText("PAUSE", button2.x + buttonWidth/2 - MeasureText("PAUSE", 50)/2, button2.y + (buttonHeight - 50)/2, 50, BLACK);
    
    DrawRectangleRec(button3, buttonColor3);
    DrawText("MENU", button3.x + buttonWidth/2 - MeasureText("MENU", 50)/2, button3.y + (buttonHeight - 50)/2, 50, BLACK);
    
    DrawRectangleRec(button4, buttonColor4);
    DrawText("QUIT", button4.x + buttonWidth/2 - MeasureText("QUIT", 50)/2, button4.y + (buttonHeight - 50)/2, 50, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), button1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        std::cout << "Bouton 1 pressed" << std::endl;
    }
    else if (CheckCollisionPointRec(GetMousePosition(), button2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        std::cout << "Bouton 2 pressed" << std::endl;
    }
    else if (CheckCollisionPointRec(GetMousePosition(), button3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        std::cout << "Bouton 3 pressed" << std::endl;
        displaySelectGame();
    }
    else if (CheckCollisionPointRec(GetMousePosition(), button4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        std::cout << "Bouton 4 pressed" << std::endl;
        CloseWindow();
    }
}


