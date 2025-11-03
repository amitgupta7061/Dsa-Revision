#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reve_rse(int num) {
        int rev = 0;
        while (num != 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] - reve_rse(nums[i]);
        }
        unordered_map<int, long long> map;
        for(int num : nums) map[num]++;

        long long result = 0, MOD = 1e9 + 7;

        for(auto &[num, cnt] : map){
            result = (result + (cnt * (cnt - 1) / 2) % MOD) % MOD;
        }
        return (int)result;
    }
};

int main() {

    return 0;
}