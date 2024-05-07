#include <vector>

int alive(const std::vector<std::vector<int>>& matrix, int row, int col) {
    int count = 0;
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            int neighborRow = row + i;
            int neighborCol = col + j;

            if (neighborRow >= 0 && neighborRow < numRows && neighborCol >= 0 && neighborCol < numCols) {
                count += matrix[neighborRow][neighborCol];
            }
        }
    }

    return count;
}

