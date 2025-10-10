#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int f(vector<int> &coins, int ind, int sum, int k, vector<vector<int>> &dp){
    if(sum == k) return 1;
    if(sum > k || ind == coins.size()) return 0;
    if(dp[ind][sum] != -1) return dp[ind][sum] % MOD;

    int pick = f(coins, ind, sum + coins[ind], k,dp) % MOD;   // can take coin multiple times
    int notpick = f(coins, ind + 1, sum, k, dp) % MOD;         // move to next coin

    return dp[ind][sum] = (pick + notpick) % MOD;
}


int f2(vector<int> &coins, int k){
    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int sum = coin; sum <= k; sum++) {
            dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
        }
    }
    return dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    vector<int> coins(n);
    for (auto &el : coins) cin >> el;

    cout << f2(coins, k);
}
