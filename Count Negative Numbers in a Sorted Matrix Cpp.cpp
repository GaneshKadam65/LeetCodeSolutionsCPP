#include <iostream>
#include <vector>

int countNegatives(std::vector<std::vector<int>>& grid) {
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    
    int row = m - 1;
    int col = 0;
    
    while (row >= 0 && col < n) {
        if (grid[row][col] < 0) {
            count += (n - col);
            row--;
        } else {
            col++;
        }
    }
    
    return count;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {-4, -3, -1,  0},
        {-2, -2,  1,  2},
        {-1,  1,  2,  3},
        { 1,  2,  4,  5}
    };
    
    int negatives = countNegatives(grid);
    
    std::cout << "Number of negative numbers: " << negatives << std::endl;
    
    return 0;
}
