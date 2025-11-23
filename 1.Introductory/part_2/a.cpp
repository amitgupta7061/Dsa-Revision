#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        vector<long long> p_count(m + 1, 0), p_sum(m + 1, 0), p_val(m + 1, 0);
        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            p_sum[i+1] = p_sum[i];
            p_count[i+1] = p_count[i];
            p_val[i+1] = p_val[i];
            if (digit != 0) {
                p_val[i+1] = (p_val[i] * 10 % MOD + digit) % MOD;
                p_count[i+1]++;
                p_sum[i+1] += digit;
            }
        }
        vector<long long> poww(m + 1);
        poww[0] = 1;
        for (int i = 1; i <= m; ++i) {
            poww[i] = (poww[i-1] * 10) % MOD;
        }
        vector<int> result;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            long long cnt = p_count[r+1] - p_count[l], sum = p_sum[r+1] - p_sum[l];
            long long temp = (p_val[l] * poww[cnt]) % MOD;
            long long x = (p_val[r+1] - temp + MOD) % MOD;
            long long ans = (x * sum) % MOD;
            result.push_back((int)ans);
        }
        return result;
    }
};

int main() {

    return 0;
}