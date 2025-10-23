#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(const string& s) {
        int n = s.length(), num1 = 0, num2 = 0;

        for (int i = 0; i + 1 < n; ++i) {
            int coefficient = nCkMod10(n - 2, i);
            num1 += (coefficient * (s[i] - '0')) % 10;
            num1 %= 10;
            num2 += (coefficient * (s[i + 1] - '0')) % 10;
            num2 %= 10;
        }

        return num1 == num2;
    }
    int nCkMod10(int n, int k) {
        int mod2 = lucasTheorem(n, k, 2);
        int mod5 = lucasTheorem(n, k, 5);
        int lookup[2][5] = {{0, 6, 2, 8, 4},{5, 1, 7, 3, 9}};
        return lookup[mod2][mod5];
    }

    int lucasTheorem(int n, int k, int prime) {
        int res = 1;
        while (n > 0 || k > 0) {
            int nMod = n % prime, kMod = k % prime;
            res *= nCk(nMod, kMod);
            res %= prime;
            n /= prime;
            k /= prime;
        }
        return res;
    }

    int nCk(int n, int k) {
        int res = 1;
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
};

int main() {

    return 0;
}