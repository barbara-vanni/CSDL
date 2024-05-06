// readFile.cpp
#include "raylib.h" // Inclure les en-têtes nécessaires

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> readMatrice(const char* filename)
{
    std::vector<std::vector<int>> matrix;

    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << std::endl;
        return matrix;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::vector<int> row;
        std::istringstream iss(line);
        char ch;
        while (iss >> ch)
        {
            if (isdigit(ch))
            {
                int value = ch - '0';
                row.push_back(value);
            }
        }
        matrix.push_back(row);
    }

    inputFile.close();

    return matrix;
}
