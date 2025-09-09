#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int f(int day, int delay, int forget, int n, vector<int> &dp) {
        if (day == 1) return 1;
        if (day <= 0) return 0;
            
        if (dp[day] != -1) return dp[day];

        long long result = 0;
        for (int prev = day - forget + 1; prev <= day - delay; prev++) {
            if (prev > 0) {
                result = (result + f(prev, delay, forget, n, dp)) % MOD;
            }
        }
        return dp[day] = (int) result;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1, -1);
        int total = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                total = (total + f(day, delay, forget, n, dp)) % MOD;
            }
        }
        return total;
    }
};


int main() {

    return 0;
}