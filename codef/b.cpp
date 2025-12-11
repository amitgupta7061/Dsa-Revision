#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> pos;
        for (int i = 0; i < n; ++i)
            if (s[i] == '1') pos.push_back(i);
        if (pos.size() == n) {
            cout << 0 << '\n';
            continue;
        }
        int m = pos.size(), ans = 0;
        for (int i = 0; i < m; ++i) {
            int j = (i + 1) % m;
            int gap = (pos[j] - pos[i] - 1 + n) % n;
            ans = max(ans, gap);
        }
        cout << ans << '\n';
    }
    return 0;
}