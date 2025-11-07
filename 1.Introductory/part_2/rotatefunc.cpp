#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result += nums[i] * i;
        }
        return result;
    }
};

int main() {

    return 0;
}