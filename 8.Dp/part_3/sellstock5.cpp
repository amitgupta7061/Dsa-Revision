#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dp[1005][505][3];

    long long dfs(vector<int> &prices, int i, int t, int state, int k) {
        if (i == prices.size()) {
            return (state == 0 ? 0 : LLONG_MIN / 2);
        }

        if (dp[i][t][state] != -1) return dp[i][t][state];

        long long ans = dfs(prices, i + 1, t, state, k);

        if (state == 0) {
            ans = max(ans, dfs(prices, i + 1, t, 1, k) - prices[i]);
            ans = max(ans, dfs(prices, i + 1, t, 2, k) + prices[i]);
        }
        else if (state == 1 && t < k) {
            ans = max(ans, dfs(prices, i + 1, t + 1, 0, k) + prices[i]);
        }
        else if (state == 2 && t < k) {
            ans = max(ans, dfs(prices, i + 1, t + 1, 0, k) - prices[i]);
        }

        return dp[i][t][state] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(prices, 0, 0, 0, k);
    }
};

int main() {

    return 0;
}