#ifndef GRID_HPP
#define GRID_HPP
#include <raylib.h>
#include <iostream>

void drawCell(int x, int y, int value);
void drawGrid(const std::vector<std::vector<int>>& matrix);

#endif