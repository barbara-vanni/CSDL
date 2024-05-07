// #include "raylib.h"

// void drawButtons()
// {
//     DrawRectangle(50, 410, 300, 50, GRAY);  
//     DrawRectangle(50, 470, 300, 50, GRAY);  
//     DrawRectangle(50, 536, 300, 50, GRAY);  
//     DrawRectangle(450, 410, 300, 50, GRAY); 
//     DrawRectangle(450, 470, 300, 50, GRAY); 
//     DrawRectangle(450, 536, 300, 50, GRAY);
// }
#include "raylib.h"
#include <iostream>


void drawButtons()
{
    Rectangle button1 = {50, 810, 300, 50};
    
    DrawRectangleRec(button1, GRAY);
    DrawText("Bouton 1", 50, 810, 40, WHITE);
    if (CheckCollisionPointRec(GetMousePosition(), button1))
    {
        DrawRectangleLinesEx(button1, 2, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            std::cout << "Bouton 1 pressed" << std::endl;
        }
    }
}