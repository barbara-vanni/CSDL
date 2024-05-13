//This file is used to save the matrix in a file and to copy the matrix in a vector
//The functions are called in the button.cpp file.
//The functions are used to save the matrix in a file and to copy the matrix in a vector

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