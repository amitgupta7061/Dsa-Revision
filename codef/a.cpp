#include<bits/stdc++.h>
using namespace std;

vector<long long> divisors;
long long ans;

void findDivisors(long long n) {
    divisors.clear();
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    divisors.push_back(n);
    sort(divisors.begin(), divisors.end());
}

void f(long long k, int ind, long long sum, long long n) {
    if (sum + k <= n) ans++;
    for (int i = ind; i < divisors.size(); ++i) {
        long long d = divisors[i];
        if (d * d > k) break;
        if (k % d == 0) {
            f(k / d, i, sum + d, n);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        ans = 0;
        findDivisors(n);
        f(n, 0, 0, n);
        cout << ans << endl;
    }
    return 0;
}