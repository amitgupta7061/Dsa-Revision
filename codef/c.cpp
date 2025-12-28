#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> nums(n);
        for(auto &it : nums) cin >> it;

        long long curr = 0;
        for (int i = 1; i < n; ++i) {
            curr -= nums[i];
        }

        long long maxi = curr;

        for (int i = 0; i < n - 1; ++i) {
            long long gain = (i == 0 ? nums[i] : abs(nums[i]));
            long long loss = nums[i+1];

            curr += gain + loss;
            maxi = max(maxi, curr);
        }

        cout << maxi << "\n";
    }
    return 0;
}