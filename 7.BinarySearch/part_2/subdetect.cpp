#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int increasing = 1, prevIncreasing = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++increasing;
            } else {
                prevIncreasing = increasing;
                increasing = 1;
            }
            if (increasing >= 2 * k || (prevIncreasing >= k && increasing >= k))
                return true;
        }

        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int low = 1, high = nums.size(), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasIncreasingSubarrays(nums, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};


int main() {

    return 0;
}