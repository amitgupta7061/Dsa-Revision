#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        char target = s[n - 1];

        int opr = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != target) opr++;
        }

        cout << opr << "\n";
    }
    return 0;
}