//grid.cpp

#include "raylib.h"

// void displayGrid()
// {
//     ClearBackground(BLACK);

//     // Dessiner la grille
//     for (int i = 0; i < 800; i += 20)
//     {
//         DrawLine(i, 0, i, 400, GRAY);
//     }

//     for (int i = 0; i <400; i += 20)
//     {
//         DrawLine(0, i, 800, i, GRAY);
//     }

//     // Dessiner les boutons
//     // for (int i = 0; i < 800; i += 400)
//     // {
//     //     DrawLine(i, 400, i, 800, GRAY);
//     // }

//     // for (int i = 400; i <800; i += 70)
//     // {
//     //     DrawLine(0, i, 800, i, GRAY);
//     // }

//     EndDrawing();
// }
void drawGrid()
{
    for (int i = 0; i < 800; i += 20)
    {
        DrawLine(i, 0, i, 800, GRAY);
        DrawLine(0, i, 800, i, GRAY);
    }
}