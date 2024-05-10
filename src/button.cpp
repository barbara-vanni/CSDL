#include "raylib.h"
#include <iostream>
#include "hpp_file/selectGame.hpp"


// void drawButtons()
// {
//     Rectangle button1 = {50, 810, 300, 50};
    
//     DrawRectangleRec(button1, GRAY);
//     DrawText("Bouton 1", 50, 810, 40, WHITE);
//     if (CheckCollisionPointRec(GetMousePosition(), button1))
//     {
//         DrawRectangleLinesEx(button1, 2, WHITE);
//         if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
//             std::cout << "Bouton 1 pressed" << std::endl;
//         }
//     }
// }
void drawButtons()
{
    // Calculer la largeur des boutons
    int buttonWidth = 300;
    
    // Calculer l'espace entre les colonnes
    int columnSpacing = (GetScreenWidth() - 2 * buttonWidth) / 3;

    // Première colonne de boutons
    Rectangle button1 = {columnSpacing, GetScreenHeight() - 150, buttonWidth, 50};
    Rectangle button2 = {columnSpacing, GetScreenHeight() - 80, buttonWidth, 50};

    // Deuxième colonne de boutons
    Rectangle button3 = {2 * columnSpacing + buttonWidth, GetScreenHeight() - 150, buttonWidth, 50};
    Rectangle button4 = {2 * columnSpacing + buttonWidth, GetScreenHeight() - 80, buttonWidth, 50};

    // Dessiner les boutons
    DrawRectangleRec(button1, GRAY);
    DrawText("SAVE", button1.x + button1.width/2 - MeasureText("Bouton 1", 30)/2, button1.y + button1.height/2 - 15, 30, WHITE);

    DrawRectangleRec(button2, GRAY);
    DrawText("PAUSE", button2.x + button2.width/2 - MeasureText("Bouton 2", 30)/2, button2.y + button2.height/2 - 15, 30, WHITE);

    DrawRectangleRec(button3, GRAY);
    DrawText("MENU", button3.x + button3.width/2 - MeasureText("Bouton 3", 30)/2, button3.y + button3.height/2 - 15, 30, WHITE);

    DrawRectangleRec(button4, GRAY);
    DrawText("QUIT", button4.x + button4.width/2 - MeasureText("Bouton 4", 30)/2, button4.y + button4.height/2 - 15, 30, WHITE);

    // Vérifier si un bouton est cliqué
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
        CloseWindow();
        displaySelectGame();
    }
    else if (CheckCollisionPointRec(GetMousePosition(), button4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        std::cout << "Bouton 4 pressed" << std::endl;
        CloseWindow();
    }
}


