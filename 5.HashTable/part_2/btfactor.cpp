#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;

        for(int num : arr) dp[num] = 1;
        int MOD = 1e9 + 7;

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j]){
                    int temp = arr[i] / arr[j];
                    if(dp.count(temp)){
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[temp]) % MOD;
                    }
                }
            }
        }

        long long result = 0;
        for(auto &[_, cnt] : dp) result = (result + cnt) % MOD;
        return result;
    }
};

int main() {

    return 0;
}