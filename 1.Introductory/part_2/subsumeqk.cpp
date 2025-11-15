#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> map{{0, 1}};

        for (int num : nums) {
            sum += num;
            if (map.count(sum-k)) ans += map[sum-k];
            map[sum]++;
        }

        return ans;
    }
};

int main() {

    return 0;
}