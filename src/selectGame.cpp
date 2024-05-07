#include "raylib.h"
#include <iostream>

void displaySelectGame()
{
    ClearBackground(BLACK);

    // Titre
    DrawText("Select your game", GetScreenWidth() / 2 - MeasureText("Select your game", 60) / 2, 100, 60, WHITE);

    // Liste des jeux
    const char* gameText[] = {"Standard", "Random", "Continue", "Pattern 1", "Pattern 2", "Pattern 3"};
    const int numGames = sizeof(gameText) / sizeof(gameText[0]);
    const int rectWidth = 400;
    const int rectHeight = 100;
    const int textSize = 40;

    // Position initiale des rectangles
    int xPos = 200;
    int yPos = 250;

    // Dessiner chaque option de jeu
    for (int i = 0; i < numGames; ++i)
    {
        // Vérifier si la souris survole le rectangle
        if (CheckCollisionPointRec(GetMousePosition(), { (float)xPos, (float)yPos, (float)rectWidth, (float)rectHeight }))
        {
            // Changement de couleur du rectangle
            DrawRectangle(xPos, yPos, rectWidth, rectHeight, RED);

            // Centrer le texte dans le rectangle
            int textXPos = xPos + (rectWidth - MeasureText(gameText[i], textSize)) / 2;
            int textYPos = yPos + (rectHeight - textSize) / 2;
            DrawText(gameText[i], textXPos, textYPos, textSize, BLACK);
        }
        else
        {
            // Rectangle standard
            DrawRectangle(xPos, yPos, rectWidth, rectHeight, WHITE);

            // Centrer le texte dans le rectangle
            int textXPos = xPos + (rectWidth - MeasureText(gameText[i], textSize)) / 2;
            int textYPos = yPos + (rectHeight - textSize) / 2;
            DrawText(gameText[i], textXPos, textYPos, textSize, BLACK);
        }

        // Déplacer la position pour le prochain rectangle
        if (i % 2 == 0)
        {
            xPos += 800;
        }
        else
        {
            xPos = 200;
            yPos += 250;
        }
    }

    EndDrawing();
}
