#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int ind, unordered_map<int,int>& freq, int k) {
        if (ind == nums.size()) return 1;

        int notTake = f(nums, ind+1, freq, k);

        int take = 0;
        if (freq[nums[ind] - k] == 0 && freq[nums[ind] + k] == 0) {
            freq[nums[ind]]++;
            take = f(nums, ind+1, freq, k);
            freq[nums[ind]]--;
        }

        return take + notTake;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> freq;
        return f(nums, 0, freq, k) - 1; 
    }
};


int main() {

    return 0;
}