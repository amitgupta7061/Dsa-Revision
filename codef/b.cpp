#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 0) cnt0++;
            if (a == 1) cnt1++;
        }
        if (cnt0 >= 1 && (cnt0 == 1 || cnt1 >= 1)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
