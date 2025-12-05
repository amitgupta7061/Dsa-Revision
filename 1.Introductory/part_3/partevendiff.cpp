#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int cnt = 0, currSum = nums[0];
        total -= nums[0];
        for(int i = 1; i < nums.size(); i++){
            currSum += nums[i];
            total -= nums[i];
            if((total - currSum) % 2 == 0){
                cnt += 1;
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}