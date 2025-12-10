#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 200005;

long long fact[MAX];
long long invFact[MAX];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (fact[n] * invFact[n - r]) % MOD;
}

int main() {
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        long long totalSum = 0;
        int limit = min(n, k);
        
        for (int d = 1; d <= limit; d++) {
            long long ways = nPr(k, d);
            long long remaining = power(k - d + 1, n - d);
            long long term = (ways * remaining) % MOD;
            totalSum = (totalSum + term) % MOD;
        }
        
        if (n <= k) {
            long long distinct = nPr(k, n);
            long long subtract = (n * distinct) % MOD;
            totalSum = (totalSum - subtract + MOD) % MOD;
        }
        
        cout << totalSum << "\n";
    }
    return 0;
}
