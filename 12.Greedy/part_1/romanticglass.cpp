#include <bits/stdc++.h>
using namespace std;

bool canpartition(vector<int> &nums){
    long long oddsum = 0, evensum = 0, balance = 0;
    set<long long> seen;
    seen.insert(0);

    for(int i = 0; i < nums.size(); i++){
        if((i+1) % 2 == 0) evensum += nums[i];
        else oddsum += nums[i];

        balance = evensum - oddsum;
        if(seen.count(balance)) return true;
        seen.insert(balance);
    }

    return false;
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        if(canpartition(nums)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}