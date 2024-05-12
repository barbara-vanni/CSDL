#ifndef ERAZER_HPP
#define ERAZER_HPP
#include <raylib.h>
#include <iostream>
#include <vector>


    // void fillMatrix(std::vector<std::vector<int>>& matrix);
    void fillMatrix();
    void copyMatrix(const std::vector<std::vector<int>>& source);
    void saveMatrixToFile(const std::string& filename);
    
#endif