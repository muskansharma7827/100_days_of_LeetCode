#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';
        if (row > 0 && grid[row - 1][col] == '1') {
            dfs(grid, row - 1, col);
        }
        if (col > 0 && grid[row][col - 1] == '1') {
            dfs(grid, row, col - 1);
        }
        if (row < grid.size() - 1 && grid[row + 1][col] == '1') {
            dfs(grid, row + 1, col);
        }
        if (col < grid[0].size() - 1 && grid[row][col + 1] == '1') {
            dfs(grid, row, col + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    dfs(grid, row, col);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}