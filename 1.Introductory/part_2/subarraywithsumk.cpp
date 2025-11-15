#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1;

        int sum = 0, maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(map.count(sum - k)){
                maxi = max(maxi, i - map[sum - k]);
            }
            if(!map.count(sum)) map[sum] = i;
        }

        return maxi;
    }
};

int main() {

    return 0;
}