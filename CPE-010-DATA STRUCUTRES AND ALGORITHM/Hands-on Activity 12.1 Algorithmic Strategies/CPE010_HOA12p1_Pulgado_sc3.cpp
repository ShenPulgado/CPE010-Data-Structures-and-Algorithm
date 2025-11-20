#include <iostream>
#include <vector>
int countPaths(std::vector<std::vector<int>>& costMatrix, int i, int j, int cost) {
    if (cost < 0) return 0;

    if (i == 0 && j == 0)
        return (cost == costMatrix[0][0]) ? 1 : 0;

    if (i < 0 || j < 0) return 0;

    return countPaths(costMatrix, i - 1, j, cost - costMatrix[i][j]) +
           countPaths(costMatrix, i, j - 1, cost - costMatrix[i][j]);
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost = 25;
    int m = matrix.size();
    int n = matrix[0].size();

    std::cout << "Number of paths with cost " << targetCost << ": "
              << countPaths(matrix, m - 1, n - 1, targetCost)
              << std::endl;

    return 0;
}
