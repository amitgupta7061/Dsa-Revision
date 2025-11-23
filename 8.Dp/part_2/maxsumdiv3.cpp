#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3);
        for (int num : nums){
            for (int sum : vector<int>(dp)){
                dp[(sum + num) % 3] = max(dp[(sum + num) % 3], sum + num);
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> memo(n + 1);
        vector<array<bool, 3>> vis(n + 1);

        function<int(int, int)> dfs = [&](int i, int mod) -> int {
            if (i == n) return (mod == 0) ? 0 : -1000000000;

            if (vis[i][mod]) return memo[i][mod];
            vis[i][mod] = true;

            int skip = dfs(i + 1, mod);
            int take = nums[i] + dfs(i + 1, (mod + nums[i]) % 3);

            return memo[i][mod] = max(skip, take);
        };

        int ans = dfs(0, 0);
        return max(0, ans);
    }
};


int main() {

    return 0;
}