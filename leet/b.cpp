#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int rem = 0;
        for (int len = 1; len <= k; len++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) return len;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.minAllOneMultiple(3) << endl;  // Expected: 3
    cout << sol.minAllOneMultiple(7) << endl;  // Expected: 6
    cout << sol.minAllOneMultiple(2) << endl;  // Expected: -1
    return 0;
}