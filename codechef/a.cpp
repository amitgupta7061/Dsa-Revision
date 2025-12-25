#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<int> C;
long long memo[105][105][105];

const long long INF = 1e18;

long long solve(int L, int R, int K) {
    // Base case: Empty subarray costs 0
    if (L > R) {
        return 0;
    }
    
    // Check memoization
    if (memo[L][R][K] != -1) {
        return memo[L][R][K];
    }
    
    long long min_cost = INF;
    for (int i = L; i <= R; ++i) {
        long long current_val_cost = (long long)A[i] * C[K];
        long long left_cost = solve(L, i - 1, K);
        long long right_cost_opt1 = solve(i + 1, R, K + 1);
        long long right_cost_opt2 = solve(i + 1, R, K + (i - L) + 1);
        
        long long total = current_val_cost + left_cost + min(right_cost_opt1, right_cost_opt2);
        
        if (total < min_cost) {
            min_cost = total;
        }
    }
    
    return memo[L][R][K] = min_cost;
}


int main() {
    
    int T;
    if (cin >> T) {
        while (T--) {
            cin >> N;
            A.resize(N);
            C.resize(N);
            
            for (int i = 0; i < N; ++i) cin >> A[i];
            for (int i = 0; i < N; ++i) cin >> C[i];
            memset(memo, -1, sizeof(memo));
            cout << solve(0, N - 1, 0) << endl;
        }
    }
    return 0;
}