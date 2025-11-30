#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> seen;
        int cnt = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int rev = f(nums[i]);
            if (seen.count(rev)) {
                cnt = min(cnt, i - seen[rev]);
            }
            seen[nums[i]] = i;
        }

        return cnt == INT_MAX ? -1 : cnt;
    }
};


int main() {

    return 0;
}