#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> colors;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            colors.insert(a);
        }
        while (true) {
            int distinctCount = colors.size();
            if (colors.count(distinctCount)) {
                cout << distinctCount << "\n";
                break;
            }
            colors.insert(distinctCount);
            if (colors.size() > 2000) {
                cout << distinctCount << "\n";
                break;
            }
        }
    }
    
    return 0;
}