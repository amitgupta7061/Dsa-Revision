#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &it : nums) cin >> it;

        long long sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            sum += abs(nums[i] - nums[i+1]);
        }

        long long mini = sum;
        long long rfirst = sum - abs(nums[0] - nums[1]);
        mini = min(mini, rfirst);
        long long rlast = sum - abs(nums[n-2] - nums[n-1]);
        mini = min(mini, rlast);

        for (int i = 1; i < n - 1; ++i) {
            long long curr = sum;
            long long cost = abs(nums[i-1] - nums[i]) + abs(nums[i] - nums[i+1]);
            long long tcost = abs(nums[i-1] - nums[i+1]);
            
            curr = curr - cost + tcost;
            mini = min(mini, curr);
        }

        cout << mini << endl;
    }
    return 0;
}