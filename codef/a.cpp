#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &x : nums) cin >> x;
        
        int zerocnt = 0;
        for (auto x : nums) if (x == 0) zerocnt++;
        
        if (zerocnt == 0) {
            cout << "Alice" << endl;
            continue;
        }
        
        if (zerocnt == 1) {
            cout << "Alice" << endl;
            continue;
        }
        if (nums[0] == 0 && nums[n-1] == 0) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    
    return 0;
}