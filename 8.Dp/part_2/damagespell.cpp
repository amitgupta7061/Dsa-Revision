#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &power, int ind, unordered_set<int> dontTake){
        if(ind >= power.size()) return 0;

        int notTake = f(power, ind+1, dontTake);
        int take = 0;
        if(!dontTake.count(power[ind])){
            dontTake.insert(power[ind] - 2);
            dontTake.insert(power[ind] - 1);
            dontTake.insert(power[ind] + 2);
            dontTake.insert(power[ind] + 1);
            take = power[ind] + f(power, ind+1, dontTake);
        }

        return max(take, notTake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_set<int> dontTake;
        return f(power, 0, dontTake);
    }
};

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> mp;
        
        for (int &x : power) mp[x]++;

        vector<long long> nums(mp.size());
        for (auto &p : mp) nums.push_back(p.first);
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<long long> t(n, 0);
        
        long long result = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            long long skip = (i + 1 < n) ? t[i + 1] : 0;

            //take current value
            int j   = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
            long long take = nums[i] * mp[nums[i]] + ((j < n) ? t[j] : 0);

            t[i]   = max(skip, take);
            result = max(result, t[i]);
        }

        return result;
    }
};


int main() {

    return 0;
}