#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> direction = {0, 1, 0, -1, 0};

    int dfs(vector<vector<int>> &grid, int r, int c, int m, int n) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return 0;

        grid[r][c] = 0;

        int area = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + direction[i], nc = c + direction[i + 1];
            area += dfs(grid, nr, nc, m, n);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int maxi = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxi = max(maxi, dfs(grid, i, j, m, n));
                }
            }
        }
        return maxi;
    }
};


int main() {

    return 0;
}