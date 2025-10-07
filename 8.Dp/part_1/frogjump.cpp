#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights) {
        vector<int> dp(heights.size(), -1);
        dp[0] = 0; dp[1] = abs(heights[0] - heights[1]);

        for(int i = 2; i < heights.size(); i++){
            dp[i] = min(dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] + abs(heights[i] - heights[i-2]));
        }
        return dp.back();
    }
};


int main() {

    return 0;
}   