#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr = 0, n = nums.size();
        vector<bool> result(n);
        for(int i = 0; i < n; i++){
            curr = (curr * 2 + nums[i]) % 5;
            result[i] = (curr % 5 == 0);
        }
        return result;
    }
};

int main() {

    return 0;
}