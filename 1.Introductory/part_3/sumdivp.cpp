#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int remainder = 0;
        for (int& num : nums) {
            remainder = (remainder + num) % p;
        }
      
        if (remainder == 0) return 0;
        unordered_map<int, int> mp;
        mp[0] = -1; 
      
        int minLength = nums.size();
        int curr = 0, n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            curr = (curr + nums[i]) % p;
            int target = (curr - remainder + p) % p;
        
            if (mp.count(target)) {
                minLength = min(minLength, i - mp[target]);
            }

            mp[curr] = i;
        }
        return minLength == n ? -1 : minLength;
    }
};


int main() {

    return 0;
}