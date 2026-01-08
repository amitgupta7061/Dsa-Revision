#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int k, int r, int c) {
        double dp[101][101] = {0.0};
        dp[0][0] = k;

        for(int i = 0; i <= r; i++){
            for(int j = 0; j <= i; j++){
                if(dp[i][j] > 1.0){
                    double overflow = dp[i][j] - 1.0;
                    dp[i][j] = 1.0;
                    dp[i+1][j] += overflow / 2.0;
                    dp[i+1][j+1] += overflow / 2.0;
                }
            }
        }
        return dp[r][c];
    }
};

int main() {

    return 0;
}