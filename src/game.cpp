#include "raylib.h"

void drawButtons();
void drawGrid();

void displayGame()
{
    BeginDrawing();

    ClearBackground(BLACK);

    // Définir une zone pour la grille (toute la largeur et jusqu'à 400 pixels en hauteur)
    BeginScissorMode(0, 0, GetScreenWidth(), 400);
    drawGrid();
    EndScissorMode();

    // Définir une zone pour les boutons (toute la largeur et de 400 jusqu'à la fin de la hauteur)
    BeginScissorMode(0, 400, GetScreenWidth(), GetScreenHeight() - 400);
    drawButtons();
    EndScissorMode();

    EndDrawing();
}

