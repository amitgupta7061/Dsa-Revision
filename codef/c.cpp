#include<bits/stdc++.h>
using namespace std;

void f() {
    string s, t;
    cin >> s >> t;

    vector<int> scnt(26, 0), tcnt(26, 0), extras(26, 0);

    for (char c : s) scnt[c - 'a']++;
    for (char c : t) tcnt[c - 'a']++;

    for (int i = 0; i < 26; ++i) {
        if (tcnt[i] < scnt[i]) {
            cout << "Impossible" << "\n";
            return;
        }
        extras[i] = tcnt[i] - scnt[i];
    }

    string result = "";
    for (char c : s) {
        int ind = c - 'a';
        for (int e = 0; e < ind; ++e) {
            while (extras[e] > 0) {
                result += (char)('a' + e);
                extras[e]--;
            }
        }
        result += c;
    }
    for (int i = 0; i < 26; ++i) {
        while (extras[i] > 0) {
            result += (char)('a' + i);
            extras[i]--;
        }
    }

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        f();
    }
    return 0;
}