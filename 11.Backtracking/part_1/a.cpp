#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        

        sort(nums.begin(), nums.end());
        
       
        vector<int> res;
        int l = 0, r = n - 1;
        bool take = true;
        
        while (l <= r) {
            if (take) {
                res.push_back(nums[l]);
                l++;
            } else {
                res.push_back(nums[r]);
                r--;
            }
            take = !take;
        }
        
        for (int i = 0; i < n; i++) {
            cout << res[i] <<" ";
        }
        cout << endl;
    }
    
    return 0;
}