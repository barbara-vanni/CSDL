#include <raylib.h>

enum Screen { MENU, GAME };

void displayMenu();
void displayGame();


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Le jeu de la vie!");
    SetTargetFPS(60);

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