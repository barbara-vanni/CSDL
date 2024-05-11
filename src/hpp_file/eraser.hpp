#ifndef ERAZER_HPP
#define ERAZER_HPP
#include <raylib.h>
#include <iostream>
#include <vector>

extern std::vector<std::vector<int>> matrix;
void writeMatrixToFile(const std::string& filename, const std::vector<std::vector<int>>& matrix);

#endif