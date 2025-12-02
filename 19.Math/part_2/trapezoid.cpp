#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> map;
        for (auto &p : points) {
            map[p[1]]++;
        }

        vector<long long> lines;  
        for (auto &[slope, cnt] : map) {
            if (cnt >= 2) {
                long long comb = (cnt * (cnt - 1) / 2) % MOD;
                lines.push_back(comb);
            }
        }

        long long result = 0, prefix = 0;
        for (long long c : lines) {
            result = (result + (prefix * c) % MOD) % MOD;
            prefix = (prefix + c) % MOD;
        }

        return result % MOD;
    }
};


int main() {

    return 0;
}

int main() {

    return 0;
}