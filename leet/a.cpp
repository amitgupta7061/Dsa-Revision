#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum = 0;
        int negind = -1, n = balance.size();

        for (int i = 0; i < n; ++i) {
            sum += balance[i];
            if (balance[i] < 0)  negind = i;
        }

        if (sum < 0) return -1;
        if (negind == -1) return 0;

        long long need = - (long long)balance[negind], ans = 0;
        vector<pair<int, int>> temp;

        for (int i = 0; i < n; i++) {
            if (balance[i] > 0) {
                int dist = abs(i - negind);
                dist = min(dist, n - dist);
                temp.push_back({dist, balance[i]});
            }
        }

        sort(temp.begin(), temp.end());
        for (auto& [dist, amt] : temp) {
            long long take = min((long long)amt, need);
            
            ans += take * dist;
            need -= take;
            if (need == 0) break;
        }

        return ans;
    }
};