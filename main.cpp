#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <sstream>


// Lire la grille depuis un fichier txt

std::string filename = "board.txt";

std::vector<std::vector<int>> readMatrixFromFile(const std::string& filename) {
    std::vector<std::vector<int>> matrix;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << '\n';
        return matrix;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int cell;
        while (iss >> cell) {
            row.push_back(cell);
            if (iss.peek() == ',' && iss.peek() =='{' && iss.peek() == '}'){
                iss.ignore();
            }
        }
        matrix.push_back(row);
    }
    return matrix;
}

// Afficher le contenu du fichier de manière brute
// void displayFileContent(const std::string& filename) {
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cerr << "Failed to open file: " << filename << '\n';
//         return;
//     }
//     std::string line;
//     while (std::getline(file, line)) {
//         for (char c : line) {
//             if (c != '{' && c != '}' && c != ',') {
//                 std::cout << c;
//             }
//             if (c == ',') {
//                 std::cout << ' ';
//             }
//         }
//         std::cout << '\n';
//     }
// }


void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << "Displaying matrix...\n";
    if (matrix.empty()) {
        std::cout << "Matrix is empty.\n";
    } else {
        for (const auto& row : matrix) {
            for (int cell : row) {
                std::cout << cell << ' ';
                std::cout <<"la cell est";
            }
            std::cout << '\n';
        }
    }
    std::cout << "Done displaying matrix.\n";
}


int main() {
    // displayFileContent("board.txt");
    std::vector<std::vector<int>> matrix = readMatrixFromFile("board.txt");
    if (matrix.empty()) {
        std::cerr << "Matrix is empty\n";
        return 1;
    }
    for (int i = 0; i < 1; ++i) { 
        displayMatrix(matrix);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}