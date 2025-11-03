#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int>& nums, int ind, vector<int>& temp, vector<vector<int>>& result) {
        if (temp.size() >= 2) result.push_back(temp);
        
        unordered_set<int> used;

        for (int i = ind; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            if (temp.empty() || nums[i] >= temp.back()) {
                used.insert(nums[i]);
                temp.push_back(nums[i]);
                f(nums, i + 1, temp, result);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        f(nums, 0, temp, result);
        return result;
    }
};


int main() {

    return 0;
}