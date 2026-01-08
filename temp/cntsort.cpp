#include <bits/stdc++.h>
using namespace std;

void cntsort(vector<int> &nums){
    int mx = *max_element(nums.begin(), nums.end());
    vector<int> cnt(mx+1, 0);

    for(int num : nums) cnt[num]++;
    int ind = 0;
    for(int i = 0; i <= mx; i++){
        while(cnt[i]--) nums[ind++] = i;
    }
}

int main() {

    return 0;
}