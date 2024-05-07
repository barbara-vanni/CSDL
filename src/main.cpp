#include <raylib.h>
#include "selectGame.hpp"
// #include "game.hpp"
#include "menu.hpp"
enum Screen { MENU, GAME };




int main()
{
    const int screenWidth = 1600;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Le jeu de la vie!");
    SetTargetFPS(20);

    Screen currentScreen = MENU;

    while (!WindowShouldClose())
    {
        if (currentScreen == MENU)
        {
            displayMenu();
        }
        else if (currentScreen == GAME)
        {
            // displayGame();
            displaySelectGame();

        }

        if (IsKeyPressed(KEY_ENTER))
        {
            if (currentScreen == MENU)
            {
                currentScreen = GAME;
            }
            else if (currentScreen == GAME)
            {
                break;
            }
        }
    }

    CloseWindow();
    return 0;
}