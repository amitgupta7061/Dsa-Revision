#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        vector<int> mn(n), mx(n);
        for (int i = 0; i < n; i++) {
            mn[i] = min(a[i], b[i]);
            mx[i] = max(a[i], b[i]);
        }
        
        vector<bool> mini(n), maxi(n);
        mini[0] = maxi[0] = true;
        
        for (int i = 1; i < n; i++) {
            if ((mini[i-1] && mn[i-1] <= mn[i]) || (maxi[i-1] && mx[i-1] <= mn[i])) {
                mini[i] = true;
            }
            if ((mini[i-1] && mn[i-1] <= mn[i]) || (maxi[i-1] && mx[i-1] <= mn[i])) {
                mini[i] = true;
            }
            if ((mini[i-1] && mn[i-1] <= mx[i]) || (maxi[i-1] && mx[i-1] <= mx[i])) {
                maxi[i] = true;
            }
        }
        
        vector<bool> mini_bot(n), maxi_bot(n);
        mini_bot[n-1] = maxi_bot[n-1] = true;
        
        for (int i = n-2; i >= 0; i--) {
            if ((mini_bot[i+1] && mn[i] <= mn[i+1]) || (maxi_bot[i+1] && mn[i] <= mx[i+1])) {
                mini_bot[i] = true;
            }
            if ((mini_bot[i+1] && mx[i] <= mn[i+1]) || (maxi_bot[i+1] && mx[i] <= mx[i+1])) {
                maxi_bot[i] = true;
            }
        }
        
        bool flag = false;
        for (int k = 0; k < n; k++) {
            if (mini[k] && maxi_bot[k]) {
                flag = true;
                break;
            }
        }
        
        cout << (flag ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
