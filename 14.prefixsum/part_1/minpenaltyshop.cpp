#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (customers[i] == 'Y');
        }
      
        int bestHour = 0, minCost = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int noCustomerPenalty = i - prefixSum[i];
            int customerPenalty = prefixSum[n] - prefixSum[i];
            int totalCost = noCustomerPenalty + customerPenalty;
            if (totalCost < minCost) {
                bestHour = i;
                minCost = totalCost;
            }
        }
      
        return bestHour;
    }
};

int main() {

    return 0;
}