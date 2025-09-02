#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    long long move = 0;
    long long prevele = nums[0];

    for(int i = 1; i < n; i++){
        if(nums[i] < prevele){
            move += (prevele - nums[i]);
        } else {
            prevele = nums[i];
        }
    }

    cout << move;
    return 0;
}
