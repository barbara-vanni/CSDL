#include "raylib.h"
#include <iostream>
#include <fstream> 
#include <ctime>
#include <cstdlib>
#include "src/hpp_file/alive.hpp"
#include <vector> 

std::vector<std::vector<int>> currentMatrix;

void saveMatrixToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const auto& row : currentMatrix) {
            for (const auto& elem : row) {
                file << elem << " ";
            }
            file << std::endl;
        }

        file.close();
        std::cout << "Matrice sauvegardée avec succès dans " << filename << std::endl;
    } else {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << " pour l'écriture." << std::endl;
    }
}

// Ajoutez cette fonction dans votre fichier eraser.cpp
void copyMatrix(const std::vector<std::vector<int>>& source) {
    currentMatrix = source;
}


void fillMatrix() {
    currentMatrix.clear();

    for (int i = 0; i < 40; ++i) {
        std::vector<int> row(80, 0); 
        currentMatrix.push_back(row);
    }
}  

// void fillMatrix(std::vector<std::vector<int>>& matrix) {
//     // Initialiser la graine pour la génération de nombres aléatoires
//     std::srand(std::time(nullptr));

//     int numRows = matrix.size();
//     int numCols = matrix[0].size();

//     // Parcourir chaque cellule de la matrice
//     for (int i = 0; i < numRows; ++i) {
//         for (int j = 0; j < numCols; ++j) {
//             // Utiliser le résultat de alive pour déterminer l'état initial de la cellule
//             matrix[i][j] = std::rand() % 2; // Choix aléatoire entre 0 et 1 pour la cellule
//         }
//     }
// }