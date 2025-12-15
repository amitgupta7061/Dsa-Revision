#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 0;
        int n = prices.size(), l = 0;

        for (int r = 1; r < n; r++) {
            if (prices[r - 1] - prices[r] != 1) {
                long long len = r - l;
                result += len * (len + 1) / 2;
                l = r;
            }
        }

        long long len = n - l;
        result += len * (len + 1) / 2;

        return result;
    }
};


int main() {

    return 0;
}