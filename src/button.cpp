#include "raylib.h"
#include <iostream>


void drawButtons()
{
    Rectangle button1 = {50, 410, 300, 50};
    
    DrawRectangleRec(button1, GRAY);
    DrawText("Bouton 1", 100, 420, 40, WHITE);
    if (CheckCollisionPointRec(GetMousePosition(), button1))
    {
        DrawRectangleLinesEx(button1, 2, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            std::cout << "Bouton 1 pressed" << std::endl;
        }
    }
}

// void drawButtons()
// {
//     DrawRectangle(50, 410, 300, 50, GRAY);   // Premier bouton
//     DrawRectangle(50, 470, 300, 50, GRAY);  // Deuxième bouton
//     DrawRectangle(50, 536, 300, 50, GRAY);  // Troisième bouton
//     DrawRectangle(450, 410, 300, 50, GRAY);  // Quatrième bouton
//     DrawRectangle(450, 470, 300, 50, GRAY);  // Cinquième bouton
//     DrawRectangle(450, 536, 300, 50, GRAY);  // Sixième bouton
// }
