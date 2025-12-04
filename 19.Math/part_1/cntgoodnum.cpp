#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long poww(long long base, long long pw){
        long long result = 1;
        while(pw > 0){
            if(pw % 2) result = (result * base) % MOD;
            base = (base * base) % MOD;
            pw /= 2;
        }
        return result % MOD;
    }
    int countGoodNumbers(long long n) {
        long long even = (poww(5, (n+1) / 2) % MOD) % MOD;
        long long odd = (poww(4, n / 2) % MOD) % MOD;
        return (int)((even * odd) % MOD);
    }
};

int main() {

    return 0;
}