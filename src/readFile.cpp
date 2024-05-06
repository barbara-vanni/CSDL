#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

std::vector<std::vector<int>> readMatrice() {
    // Ouvrir le fichier en lecture
    ifstream inputFile("board.txt");

    if (!inputFile.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        return {};
    }

    string line;
    vector<vector<int>> matrix; // Pour stocker la matrice

    // Lire chaque ligne du fichier
    while (getline(inputFile, line)) {
        vector<int> row; // Pour stocker une ligne de la matrice

        // Utiliser un stringstream pour séparer les valeurs de la ligne
        stringstream ss(line);
        char ch;

        // Lire les valeurs entre {}
        while (ss >> ch) {
            if (isdigit(ch)) {
                int value = ch - '0'; // Convertir le caractère en entier
                row.push_back(value);
            }
        }

        // Ajouter la ligne à la matrice
        matrix.push_back(row);
    }

    // Fermer le fichier après lecture
    inputFile.close();

    // Afficher la matrice avec * pour les 1 et des cases vides pour les 0
    for (const auto& row : matrix) {
        for (int value : row) {
            if (value == 1) {
                cout << "* ";
            } else {
                cout << "  "; // Deux espaces pour représenter une case vide
            }
        }
        cout << endl;
    }

    return matrix;
}
