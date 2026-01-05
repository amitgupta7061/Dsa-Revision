#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long p;
        cin >> n >> p;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<pair<long long, long long>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({b[i], a[i]});
        }

        sort(v.begin(), v.end());
        long long totalCost = p, informed = 1;

        for (auto &it : v) {
            if (informed >= n) break;

            long long cost = it.first, canShare = it.second;
            if (cost >= p) break;

            long long remaining = n - informed;
            long long used = min(canShare, remaining);

            totalCost += used * cost;
            informed += used;
        }

        if (informed < n) {
            totalCost += (n - informed) * p;
        }

        cout << totalCost << "\n";
    }

    return 0;
}
