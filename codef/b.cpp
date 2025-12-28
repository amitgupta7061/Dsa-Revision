#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string r;
        cin >> r;

        for (char c : r) {
            assert(c == 's' || c == 'u');
        }

        int n = r.length();
        
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(2, INF));

        dp[0][0] = (r[0] == 'u');

        for (int i = 1; i < n; ++i) {
            int costs = (r[i] == 'u'), costu = (r[i] == 's');

            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + costs;

            if (dp[i-1][0] != INF) dp[i][1] = dp[i-1][0] + costu;

        }

        cout << dp[n-1][0] << "\n";
    }
    return 0;
}