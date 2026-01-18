class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size(), MOD = 1e9 + 7;
        vector<int> temp1(200000, 0), temp2(200000, 0);
        temp1[0] = 1;

        int curr = 0, result = 0;

        for (int i = 0; i < n; ++i) {
            curr ^= nums[i];
            
            int ways1 = 0, need1 = curr ^ target1;
            if (need1 < 200000) ways1 = temp1[need1];

            int ways2 = 0, need2 = curr ^ target2;
            if (need2 < 200000) ways2 = temp2[need2];
            temp2[curr] = (temp2[curr] + ways1) % MOD;
            temp1[curr] = (temp1[curr] + ways2) % MOD;
            if (i == n - 1) result = (ways1 + ways2) % MOD;
        }

        return result;
    }
};