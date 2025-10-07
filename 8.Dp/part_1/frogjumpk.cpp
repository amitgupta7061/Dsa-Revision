#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0)
                    dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
        return dp[n - 1];
    }
};



int main() {

    return 0;
}