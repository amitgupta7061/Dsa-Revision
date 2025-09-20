#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums, int x, int y){
    
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> nums(n);
        for(auto &num : nums) cin >> num;

        cout<<f(nums, x, y)<<"\n";
    }

    return 0;
}