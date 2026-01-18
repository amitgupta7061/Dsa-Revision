#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (is_sorted(s.begin(), s.end())) {
            cout << "Bob" << endl;
            continue;
        }

        int cnt0 = count(s.begin(), s.end(), '0');
        vector<int> moves;
        
        for (int i = 0; i < cnt0; ++i) if (s[i] == '1') moves.push_back(i + 1);
        for (int i = cnt0; i < n; ++i) if (s[i] == '0') moves.push_back(i + 1);

        cout << "Alice" << endl;
        cout << moves.size() << endl;
        for (size_t i = 0; i < moves.size(); ++i) cout << moves[i] << (i == moves.size() - 1 ? "" : " ");
        cout << endl;
    }
    return 0;
}