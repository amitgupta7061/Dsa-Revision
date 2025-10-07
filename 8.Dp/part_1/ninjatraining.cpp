#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>>& matrix, int r, int curr, vector<vector<int>>& dp) {
        if (r >= matrix.size()) return 0;
        if (curr != -1 && dp[r][curr] != -1) return dp[r][curr];
        
        int result = 0;
        for (int i = 0; i < 3; i++) {
            if (i == curr) continue;
            result = max(result, matrix[r][i] + f(matrix, r + 1, i, dp));
        }
        if (curr != -1) dp[r][curr] = result;
        return result;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(matrix, 0, -1, dp);
    }
};


int main() {

    return 0;
}