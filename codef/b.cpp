#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        long long a, b, n;
        cin >> a >> b >> n;

        if (a == b) {
            cout<<1<<"\n";
            continue;
        }
        long long temp = a / b;

        if (n <= temp) cout<<1<<"\n";
        else cout<<2<<"\n";
    }
    return 0;
}
