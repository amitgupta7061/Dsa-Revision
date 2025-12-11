#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    
    int f(vector<vector<int>> &grid, int r, int c1, int c2, vector<vector<vector<int>>> &dp){
        if(c1 < 0 or c1 >= n or c2 < 0 or c2 >= n) return -99999;
        if(r == m-1){
            if(c1 == c2) return grid[r][c1];
            else return grid[r][c1] + grid[r][c2];
        }
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int maxi = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(c1 == c2){
                    maxi = max(maxi, grid[r][c1] + f(grid, r+1, c1+i, c2+j, dp));
                } else{
                    maxi = max(maxi, grid[r][c1] + grid[r][c2] + f(grid, r+1, c1+i, c2+j, dp));
                }
            }
        }
        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return f(grid, 0, 0, n-1, dp);
    }
};

int main() {

    return 0;
}