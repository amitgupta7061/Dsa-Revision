#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canpossible(vector<int> stations, int r, int k, long mid) {
        int n = stations.size();
        long power = accumulate(stations.begin(), stations.begin() + r, 0L);

        for (int i = 0; i < n; ++i) {
            if (i + r < n) power += stations[i + r];
            if (power < mid) {
                long requiredPower = mid - power;
                if (requiredPower > k) return false;
                stations[min(n - 1, i + r)] += requiredPower;
                k -= requiredPower;
                power += requiredPower;
            }
            if (i - r >= 0) power -= stations[i - r];
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        long left = *min_element(stations.begin(), stations.end());
        long right = accumulate(stations.begin(), stations.end(), 0L) + k + 1;

        while (left < right) {
            long mid = (left + right) / 2;
            if (canpossible(stations, r, k, mid)) left = mid + 1;
            else right = mid;
        }

        return left - 1;
    }
};

int main() {

    return 0;
}