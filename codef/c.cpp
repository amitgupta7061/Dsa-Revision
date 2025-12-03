#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N), B(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) cin >> B[i];

    vector<long long> leftA(N), rightA(N);
    vector<long long> leftB(N), rightB(N);

    leftA[0] = A[0];
    leftA[0] = A[0];
    for(int i = 1; i < N; ++i) {
        leftA[i] = max(A[i], A[i] + leftA[i-1]);
    }
    rightA[N-1] = A[N-1];
    for(int i = N - 2; i >= 0; --i) {
        rightA[i] = max(A[i], A[i] + rightA[i+1]);
    }
    leftB[0] = B[0];
    for(int i = 1; i < N; ++i) {
        leftB[i] = max(B[i], B[i] + leftB[i-1]);
    }
    rightB[N-1] = B[N-1];
    for(int i = N - 2; i >= 0; --i) {
        rightB[i] = max(B[i], B[i] + rightB[i+1]);
    }

    long long max_score = -4e18;

    for(int i = 0; i < N; ++i) {
        long long max_A_at_i = leftA[i] + rightA[i] - A[i];
        long long max_B_at_i = leftB[i] + rightB[i] - B[i];
        if (max_A_at_i + max_B_at_i > max_score) {
            max_score = max_A_at_i + max_B_at_i;
        }
    }

    cout << max_score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}