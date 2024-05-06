// main.cpp
#include "raylib.h"
#include "grid.h" // Inclure le fichier d'en-tête correspondant

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Affichage de la matrice dans le terminal");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        drawGrid();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
