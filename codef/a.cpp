#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        int cnt = count(s.begin(), s.end(), 'Y');
        cout << (cnt <= 1 ? "YES" : "NO") << "\n";
    }
    
    return 0;
}