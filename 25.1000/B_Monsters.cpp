#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         long long k;
//         cin >> n >> k;
//         priority_queue<pair<long long, int>> pq;

//         for (int i = 1; i <= n; i++) {
//             long long health;
//             cin >> health;
//             pq.push({health, -i});
//         }

//         while (pq.size()) {
//             auto [health, negIdx] = pq.top(); pq.pop();

//             if (health <= k) cout << -negIdx << " ";
//             else pq.push({health - k, negIdx});
//         }
//         cout << "\n";
//     }
//     return 0;
// }

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<pair<long long, int>> monsters;

        for (int i = 1; i <= n; i++) {
            long long a;
            cin >> a;
            long long rem = a % k;
            if (rem == 0) rem = k; 
            monsters.push_back({rem, i});
        }

        sort(monsters.begin(), monsters.end(), [](auto &x, auto &y) {
            if (x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        });

        for (auto &m : monsters) {
            cout << m.second << " ";
        }
        cout << "\n";
    }

    return 0;
}
