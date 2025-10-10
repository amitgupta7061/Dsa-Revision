#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int f(vector<vector<char>> &mat, int x, int y, int n, vector<vector<int>> &dp){
    if(x >= n || x < 0 || y < 0 || y >= n) return 0;
    if(mat[x][y] == '*') return 0;
    if(x == n-1 && y == n-1) return 1;
    if(dp[x][y] != -1) return dp[x][y] % MOD;

    return dp[x][y] = (f(mat, x+1, y, n, dp) % MOD + f(mat, x, y+1, n, dp) % MOD) % MOD;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> mat(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << f(mat, 0, 0, n, dp) << "\n";

    return 0;
}
