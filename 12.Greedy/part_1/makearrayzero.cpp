#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> prefix(n);
        vector<int> suffix(n);

        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + nums[i - 1];

        for (int i = n - 2; i >= 0; --i)
            suffix[i] = suffix[i + 1] + nums[i + 1];

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) continue;
            if (prefix[i] == suffix[i]) ans += 2;
            if (abs(prefix[i] - suffix[i]) == 1) ans += 1;
        }

        return ans;
    }
};

int main() {

    return 0;
}