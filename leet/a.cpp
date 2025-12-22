#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        unordered_map<int, int> numfreq, forbfreq;
        for (auto it : nums) numfreq[it]++;
        for (auto it : forbidden) forbfreq[it]++;

        for (auto &[val, cnt] : numfreq) {
            if ((long long)cnt + forbfreq[val] > nums.size())  return -1;
        }

        unordered_map<int, int> mp;
        int total = 0, maxi = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == forbidden[i]) {
                mp[nums[i]]++;
                total++;
            }
        }

        for (auto &[val, cnt] : mp) {
            maxi = max(maxi, cnt);
        }
        
        return max(maxi, (total + 1) / 2);
    }
};