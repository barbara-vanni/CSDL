#include <raylib.h>

enum Screen { MENU, GAME };

void displayMenu();
void displayGame();


int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Le jeu de la vie!");
    SetTargetFPS(10);

    Screen currentScreen = MENU;

    while (!WindowShouldClose())
    {
        if (currentScreen == MENU)
        {
            displayMenu();
        }
        else if (currentScreen == GAME)
        {
            displayGame();
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