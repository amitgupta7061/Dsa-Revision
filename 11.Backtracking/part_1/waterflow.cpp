#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

double waterOverflow(int K, int R, int C) {
    double dp[505][505] = {0.0};
    dp[1][1] = K;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[i][j] > 1.0) {
                double overflow = dp[i][j] - 1.0;
                dp[i][j] = 1.0;
                dp[i + 1][j] += overflow / 2.0;
                dp[i + 1][j + 1] += overflow / 2.0;
            }
        }
    }
    return min(1.0, dp[R][C]);
}


int main() {

    return 0;
}