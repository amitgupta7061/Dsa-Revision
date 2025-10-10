#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    const int MOD = 1e9 + 7;

    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        long long sum = 0;
        for(int k = 1; k <= 6; k++){
            if(i - k < 0) break;
            sum += dp[i-k];
        }
        dp[i] = sum % MOD;
    }

    cout<<dp[n];

    return 0;
}