#include "raylib.h"
#include <iostream>

void displayMenu()
{

    ClearBackground(BLACK);


    DrawText("Welcome to the game!", 200, 200, 30, WHITE);
    DrawText("Press Enter to start the game.", 200, 250, 20, WHITE);

    EndDrawing();
}