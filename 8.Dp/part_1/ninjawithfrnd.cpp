#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChocolates(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        function<int(int,int,int)> f = [&](int r, int c1, int c2) -> int {
            if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) return -1e9;
            if (r == m - 1) return (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
            if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

            int maxChoco = -1e9;
            for (int dc1 = -1; dc1 <= 1; dc1++) {
                for (int dc2 = -1; dc2 <= 1; dc2++) {
                    int next = f(r + 1, c1 + dc1, c2 + dc2);
                    maxChoco = max(maxChoco, next);
                }
            }

            int curr = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
            return dp[r][c1][c2] = curr + maxChoco;
        };

        return f(0, 0, n - 1);
    }
};

int main() {

    return 0;
}