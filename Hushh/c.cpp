#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

long long pw(long long b, long long e) {
    long long r = 1;
    b %= MOD;
    while (e) {
        if (e & 1) r = (r * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return r;
}

long long inv(long long x) {
    return pw(x, MOD - 2);
}

void dfs(int u, vector<vector<int>> &ch, vector<int> &par, vector<long long> &val, vector<long long> &dp, vector<long long> &prd) {
    if (ch[u].empty()) { dp[u] = val[u]; return; }
    long long tot = 1;
    for (int v : ch[u]) { dfs(v, ch, par, val, dp, prd); tot = (tot * dp[v]) % MOD; }
    dp[u] = (val[u] + tot) % MOD;

    int sz = ch[u].size();
    if (sz) {
        vector<long long> pre(sz), suf(sz);
        pre[0] = dp[ch[u][0]];
        for (int i = 1; i < sz; ++i) pre[i] = (pre[i - 1] * dp[ch[u][i]]) % MOD;
        suf[sz - 1] = dp[ch[u][sz - 1]];
        for (int i = sz - 2; i >= 0; --i) suf[i] = (suf[i + 1] * dp[ch[u][i]]) % MOD;
        for (int i = 0; i < sz; ++i) {
            int v = ch[u][i];
            long long l = (i == 0 ? 1 : pre[i - 1]);
            long long r = (i == sz - 1 ? 1 : suf[i + 1]);
            prd[v] = (l * r) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> par(n + 1);
    vector<vector<int>> ch(n + 1);
    for (int i = 2; i <= n; ++i) { cin >> par[i]; ch[par[i]].push_back(i); }
    vector<long long> val(n + 1);
    for (int i = 1; i <= n; ++i) cin >> val[i];

    vector<long long> dp(n + 1), prd(n + 1, 1);
    dfs(1, ch, par, val, dp, prd);

    while (q--) {
        int u; long long x; cin >> u >> x;
        long long oldVal = val[u];
        val[u] = x;
        long long delta = (x - oldVal + MOD) % MOD;

        int cur = u;
        while (cur) {
            long long oldDp = dp[cur];
            dp[cur] = (dp[cur] + delta) % MOD;
            if (cur == 1 || delta == 0) break;
            int p = par[cur];
            long long oldPrd = prd[cur];

            if (ch[p].size() > 1) {
                if (oldDp) {
                    long long m = (dp[cur] * inv(oldDp)) % MOD;
                    for (int s : ch[p]) if (s != cur) prd[s] = (prd[s] * m) % MOD;
                } else {
                    int sz = ch[p].size();
                    vector<long long> pre(sz), suf(sz);
                    pre[0] = dp[ch[p][0]];
                    for (int i = 1; i < sz; ++i) pre[i] = (pre[i - 1] * dp[ch[p][i]]) % MOD;
                    suf[sz - 1] = dp[ch[p][sz - 1]];
                    for (int i = sz - 2; i >= 0; --i) suf[i] = (suf[i + 1] * dp[ch[p][i]]) % MOD;
                    for (int i = 0; i < sz; ++i) {
                        int v = ch[p][i];
                        if (v == cur) continue;
                        long long l = (i == 0 ? 1 : pre[i - 1]);
                        long long r = (i == sz - 1 ? 1 : suf[i + 1]);
                        prd[v] = (l * r) % MOD;
                    }
                }
            }
            delta = (delta * oldPrd) % MOD;
            cur = p;
        }
        cout << dp[1] << "\n";
    }
}
