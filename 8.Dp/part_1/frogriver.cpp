#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool f(vector<int>& stones, int ind, int lastJump, unordered_map<int,int>& posMap, vector<vector<int>> &dp) {
        if (ind == stones.size() - 1) return true;
        if(dp[ind][lastJump] != -1) return dp[ind][lastJump];
        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            if (jump <= 0) continue;

            int nextPos = stones[ind] + jump;
            if (posMap.count(nextPos)) {
                int nextInd = posMap[nextPos];
                if (f(stones, nextInd, jump, posMap, dp)) return dp[ind][lastJump] =  true;
            }
        }
        return dp[ind][lastJump] = false;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int,int> posMap;
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size() + 1, -1));

        for (int i = 0; i < stones.size(); i++) posMap[stones[i]] = i;

        return f(stones, 0, 0, posMap,dp);
    }
};

int main() {

    return 0;
}