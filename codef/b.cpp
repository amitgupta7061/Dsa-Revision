#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<bool> present(n + 2, false);
        for (int x : a) {
            if (x <= n) present[x] = true;
        }
        int cnt = 0;
        while (present[cnt]) cnt++;
        
        cout << min(cnt, k - 1) << "\n";
    }
    
    return 0;
}
