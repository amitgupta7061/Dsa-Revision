#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefsum(n+1, 0), best(k, LLONG_MAX);

        for (int i = 0; i < n; i++) prefsum[i+1] = prefsum[i] + nums[i];

        long long result = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int r = i % k;

            if (best[r] != LLONG_MAX) {
                result = max(result, prefsum[i] - best[r]);
            }
            best[r] = min(best[r], prefsum[i]);
        }

        return result;
    }
};



int main() {

    return 0;
}