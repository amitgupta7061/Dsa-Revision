#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> x(n);
        for(auto &it : x) cin >> it;

        if (n < 2) {
            cout << 0 << "\n";
            continue;
        }

        long long res = 0;

        for (int i = 0; i < n - 1; i++) {
            if (x[i+1] - x[i] == 1) res++;
        }
        cout << res << "\n";
    }
    return 0;
}