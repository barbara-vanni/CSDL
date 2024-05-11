#include "raylib.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

void writeMatrixToFile(const std::string& filename, const std::vector<std::vector<int>>& matrix)
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        for (const auto& row : matrix)
        {
            for (int value : row)
            {
                file << value << " ";
            }
            file << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}