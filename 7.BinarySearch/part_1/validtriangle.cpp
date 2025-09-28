#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
      
        int count = 0, n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) continue;
          
            for (int j = i + 1; j < n - 1; ++j) {
                int targetSum = nums[i] + nums[j];
                int k = lower_bound(nums.begin() + j + 1, nums.end(), targetSum) - nums.begin();
                count += (k - 1) - j;
            }
        }
      
        return count;
    }
};


int main() {

    return 0;
}