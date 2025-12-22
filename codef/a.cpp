#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, a, b;
        cin >> l >> a >> b;

        int g = gcd(l, b), steps = l / g;
        int pos = a, res = pos;

        for (int i = 1; i < steps; i++) {
            pos = (pos + b) % l;
            res = max(res, pos);
        }

        cout << res << "\n";
    }
    return 0;
}
