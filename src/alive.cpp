#include <vector>

int alive(const std::vector<std::vector<int>>& matrix, int row, int col) {
    int count = 0;
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            // Exclure la cellule actuelle
            if (i == 0 && j == 0) {
                continue;
            }

            // Coordonnées de la cellule voisine
            int neighborRow = row + i;
            int neighborCol = col + j;

            // Vérifier si la cellule voisine est à l'intérieur de la grille
            if (neighborRow >= 0 && neighborRow < numRows && neighborCol >= 0 && neighborCol < numCols) {
                // Incrémenter le compteur si la cellule voisine est vivante
                count += matrix[neighborRow][neighborCol];
            }
        }
    }

    return count;
}


// int alive(const std::vector<std::vector<int>>& matrix, int row, int col) {
//     int count = 0;
//     int numRows = matrix.size();
//     int numCols = matrix[0].size();

//     // Parcours des cellules voisines dans un carré 3x3 autour de la cellule actuelle
//     for (int i = -1; i <= 1; ++i) {
//         for (int j = -1; j <= 1; ++j) {
//             // Exclure la cellule actuelle
//             if (i == 0 && j == 0) {
//                 continue;
//             }

//             // Coordonnées de la cellule voisine
//             int neighborRow = row + i;
//             int neighborCol = col + j;

//             // Vérifier si la cellule voisine est à l'intérieur de la grille
//             if (neighborRow >= 0 && neighborRow < numRows && neighborCol >= 0 && neighborCol < numCols) {
//                 // Incrémenter le compteur si la cellule voisine est vivante
//                 count += matrix[neighborRow][neighborCol];
//             }
//         }
//     }

//     // Appliquer les règles du jeu de la vie
//     if (matrix[row][col] == 1) {
//         // Cellule vivante
//         if (count < 2 || count > 3) {
//             // Moins de 2 ou plus de 3 voisins vivants, la cellule meurt
//             return 0;
//         } else {
//             // Entre 2 et 3 voisins vivants, la cellule reste vivante
//             return 1;
//         }
//     } else {
//         // Cellule morte
//         if (count == 3) {
//             // Exactement 3 voisins vivants, la cellule devient vivante
//             return 1;
//         } else {
//             // Autrement, la cellule reste morte
//             return 0;
//         }
//     }
// }

