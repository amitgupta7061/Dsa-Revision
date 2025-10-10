#include <bits/stdc++.h>
using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for(auto &it : coins) cin >> it;

    vector<int> dp(k+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= k; i++){
        for(auto & coin : coins){
            if(coin <= i and dp[i - coin] != INT_MAX){
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout<<((dp[k] == INT_MAX) ? -1 : dp[k]);
    return 0;
}