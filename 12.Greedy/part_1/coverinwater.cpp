#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 0, len = 0;
        for (int i = 0; i <= n; i++) {
            if (i < n && s[i] == '.') {
                len++;
            } else {
                if(len >= 3){
                    ans = 2;
                    break;
                }
                if (len > 0) {
                    ans += min(len, 2);
                    len = 0;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
