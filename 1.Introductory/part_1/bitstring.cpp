#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    cout << modPow(2, n, MOD) << "\n";

    return 0;
}
