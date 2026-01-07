#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        long long lmaxi = k - 1, rmaxi = n - k, result = 1;

        for (long long l = 0; l <= lmaxi; ++l) {
            if (2 * l - 1 <= m) {
                long long cost = m + 1 - 2 * l;
                long long r = min({rmaxi, l, cost});
                
                if (r >= 0) {
                    result = max(result, l + r + 1);
                }
            }
            
            long long cost = (m + 1 - l) / 2, r = min(rmaxi, cost);
            
            if (r > l) {
                result = max(result, l + r + 1);
            }
        }

        cout << result << endl;
    }
    return 0;
}