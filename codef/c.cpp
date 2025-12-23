#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> nums(n);
        for(auto &it : nums) cin >> it;
        sort(nums.begin(), nums.end());
        long long fst = nums[0], mini = -1;
        
        for (int i = 1; i < n; ++i) {
            long long diff = nums[i] - nums[0];
            if (mini == -1 or diff < mini)  mini = diff;
        }
        
        long long scnd = mini;
        cout << max(fst, scnd) << endl;
    }
    return 0;
}