#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int cnt = 1 << n, curr = (1 << n) - 1;
        vector<int> visited(cnt, false), perm, mask;
        perm.reserve(cnt);
        
        while (true) {
            mask.push_back(curr);
            if (curr == 0) break;
            int ind = 31 - __builtin_clz(curr);
            curr ^= (1 << ind);
        }

        for (auto it : mask) {
            for (int i = 0; i < cnt; i++) {
                if (!visited[i]) {
                    if ((i & it) == it) {
                        visited[i] = true;
                        perm.push_back(i);
                    }
                }
            }
        }
        for (int i = 0; i < cnt; i++) {
            cout << perm[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}