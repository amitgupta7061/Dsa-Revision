#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> directions = {0, 1, 0, -1, 0};
    int f(vector<vector<int>> &grid, int r, int c){
        if(r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size() or grid[r][c] == 0) return 0;

        int maxi = 0;
        for(int d = 0; d < 4; d++){
            int nr = r + directions[d], nc = c + directions[d+1];
            int gold = grid[r][c];
            grid[r][c] = 0;
            maxi = max(maxi, gold + f(grid, nr, nc));
            grid[r][c] = gold;
        }

        return maxi;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxi = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                maxi = max(maxi, f(grid, i, j));
            }
        }
        return maxi;
    }
};

int main() {

    return 0;
}