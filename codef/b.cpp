#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<long long> maxSufA(n), maxPreA(n);
        vector<long long> maxSufB(n), maxPreB(n);
        

        maxSufA[0] = a[0];
        maxSufB[0] = b[0];
        for (int i = 1; i < n; i++) {
            maxSufA[i] = max(a[i], maxSufA[i-1] + a[i]);
            maxSufB[i] = max(b[i], maxSufB[i-1] + b[i]);
        }
        
        maxPreA[n-1] = a[n-1];
        maxPreB[n-1] = b[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxPreA[i] = max(a[i], maxPreA[i+1] + a[i]);
            maxPreB[i] = max(b[i], maxPreB[i+1] + b[i]);
        }
        
        vector<long long> bestA(n), bestB(n);
        for (int i = 0; i < n; i++) {
            bestA[i] = maxSufA[i] + maxPreA[i] - a[i];
            bestB[i] = maxSufB[i] + maxPreB[i] - b[i];
        }
        
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, bestA[i] + bestB[i]);
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}