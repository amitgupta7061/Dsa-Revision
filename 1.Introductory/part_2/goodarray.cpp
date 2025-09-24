#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> nums(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    unordered_map<long long, int> freq;
    for (int num : nums) freq[num]++;

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        long long remaining = sum - nums[i];
        if (remaining % 2 != 0) continue;

        long long target = remaining / 2;

        if (freq.count(target)) {
            if (target == nums[i]) {
                if (freq[target] > 1) ans.push_back(i + 1);
            } else {
                ans.push_back(i + 1);
            }
        }
    }

    cout << ans.size() << "\n";
    for (int idx : ans) cout << idx << " ";
    cout << "\n";

    return 0;
}
