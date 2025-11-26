#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n, MOD = 1e9 + 7;
    int f(vector<vector<int>> &grid, int r, int c, int sum, int k, vector<vector<vector<int>>> &dp){
        if(r < 0 or r >= m or c < 0 or c >= n) return 0;
        if(r == m-1 and c == n-1){
            sum += grid[r][c] % k;  
            return (sum % k == 0);
        }
        sum = sum % k;
        if(dp[r][c][sum] != -1) return dp[r][c][sum] % MOD;

        return dp[r][c][sum] = (f(grid, r+1, c, sum+grid[r][c] % k, k, dp) % MOD 
                             + f(grid, r, c+1, sum+grid[r][c] % k, k, dp) % MOD) % MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return f(grid, 0, 0, 0, k, dp);
    }
};

int main() {

    return 0;
}