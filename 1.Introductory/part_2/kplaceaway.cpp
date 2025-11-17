#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prevInd = -(k + 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - prevInd - 1 < k) return false;
                prevInd = i;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}