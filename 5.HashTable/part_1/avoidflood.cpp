#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> result(n, 1);
        unordered_map<int, int> lastRain; // lake -> last day it rained
        set<int> dryDays; // store indices of dry days (sorted)

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                result[i] = -1;
                
                if (lastRain.count(rains[i])) {
                    int prevDay = lastRain[rains[i]];
                    
                    auto it = dryDays.upper_bound(prevDay);
                    if (it == dryDays.end()) return {};
                    result[*it] = rains[i];
                    dryDays.erase(it);
                }
                lastRain[rains[i]] = i;
            }
        }

        return result;
    }
};


int main() {

    return 0;
}