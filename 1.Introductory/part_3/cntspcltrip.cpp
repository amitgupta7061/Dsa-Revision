#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> left, rght;
        for(int num : nums) rght[num]++;

        long long result = 0; int MOD = 1e9 + 7;
        for(int mid : nums){
            rght[mid]--;
            int target = mid * 2;
            result = (result + 1LL * left[target] * rght[target] % MOD) % MOD;
            left[mid]++;
        }
        return result;
    }
};

int main() {

    return 0;
}