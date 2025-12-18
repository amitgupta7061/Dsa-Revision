#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> prefixsum(n), pricesum(n);
        pricesum[0] =  prices[0];
        prefixsum[0] = prices[0] * strategy[0];
        for(int i = 1; i < n; i++){
            prefixsum[i] = prefixsum[i-1] + (prices[i] * strategy[i]);
            pricesum[i] = pricesum[i-1] + prices[i];
        }
        long long result = prefixsum.back(), maxi = result;
        for(int i = 0; i < n - k + 1; i++){
            int fs = i, fe = (i + (k / 2)) - 1;   // first start and first end
            int ss = i + (k / 2), se = i + k - 1;   // second start and second end

            long long firstsum = prefixsum[fe] - (fs > 0 ? prefixsum[fs-1] : 0);
            long secondsum = prefixsum[se] - prefixsum[ss-1];

            long newsecondsum = pricesum[se] - pricesum[ss-1];

            long long newsum = result - firstsum - secondsum + newsecondsum;
            maxi = max(maxi, newsum);
        }
        return maxi;
    }
};
   

int main() {

    return 0;
}