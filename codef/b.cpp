#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> p(n + 1);
        iota(p.begin(), p.end(), 0); 
        p[r] = p[l - 1];
        for (int i = 1; i <= n; ++i) {
            cout << (p[i] ^ p[i - 1]) << (i == n ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}