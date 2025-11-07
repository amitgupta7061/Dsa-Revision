#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

bool isAncestor(int u, int v, vector<int> &tin, vector<int> &tout) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int findLCA(int a, int b, int LOG, vector<int> &tin, vector<int> &tout, vector<vector<int>> &up) {
    if (isAncestor(a, b, tin, tout)) return a;
    if (isAncestor(b, a, tin, tout)) return b;

    for (int i = LOG - 1; i >= 0; --i) {
        if (!isAncestor(up[i][a], b, tin, tout)) {
            a = up[i][a];
        }
    }
    return up[0][a];
}

void preprocessDFS(int u, int p, int LOG, vector<vector<int>> &tree,
                   vector<vector<int>> &up, vector<int> &depth,
                   vector<int> &tin, vector<int> &tout, int &timer) {
    tin[u] = ++timer;
    up[0][u] = (p == 0 ? u : p);
    for (int i = 1; i < LOG; i++)
        up[i][u] = up[i - 1][up[i - 1][u]];

    for (int v : tree[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            preprocessDFS(v, u, LOG, tree, up, depth, tin, tout, timer);
        }
    }
    tout[u] = ++timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    int LOG = 1;
    while ((1 << LOG) <= n) LOG++;

    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<vector<int>> up(LOG, vector<int>(n + 1));
    vector<int> depth(n + 1), tin(n + 1), tout(n + 1);
    int timer = 0;
    preprocessDFS(1, 0, LOG, tree, up, depth, tin, tout, timer);

    vector<vector<pair<int, int>>> virtualTree(n + 1);
    vector<int> mark(n + 1, 0);

    while (q--) {
        int k;
        cin >> k;
        vector<int> nodes(k);
        for (int i = 0; i < k; i++) {
            cin >> nodes[i];
            mark[nodes[i]] = 1;
        }

        sort(nodes.begin(), nodes.end(), [&](int a, int b) { return tin[a] < tin[b]; });

        vector<int> all = nodes;
        for (int i = 1; i < k; i++) {
            int L = findLCA(nodes[i - 1], nodes[i], LOG, tin, tout, up);
            if (!mark[L]) {
                all.push_back(L);
                mark[L] = 2;
            }
        }

        sort(all.begin(), all.end(), [&](int a, int b) { return tin[a] < tin[b]; });
        vector<int> stk;
        if (!all.empty()) stk.push_back(all[0]);

        for (int i = 1; i < (int)all.size(); i++) {
            int node = all[i];
            int L = findLCA(node, stk.back(), LOG, tin, tout, up);

            if (L == stk.back()) {
                stk.push_back(node);
                continue;
            }

            while (stk.size() >= 2 && depth[stk[stk.size() - 2]] >= depth[L]) {
                int child = stk.back();
                stk.pop_back();
                int parent = stk.back();
                int w = depth[child] - depth[parent];
                virtualTree[parent].push_back({child, w});
                virtualTree[child].push_back({parent, w});
            }

            if (stk.back() != L) {
                int child = stk.back();
                stk.pop_back();
                int w = depth[child] - depth[L];
                virtualTree[L].push_back({child, w});
                virtualTree[child].push_back({L, w});
                stk.push_back(L);
            }
            stk.push_back(node);
        }

        while (stk.size() >= 2) {
            int child = stk.back();
            stk.pop_back();
            int parent = stk.back();
            int w = depth[child] - depth[parent];
            virtualTree[parent].push_back({child, w});
            virtualTree[child].push_back({parent, w});
        }

        int root = all.empty() ? 0 : all[0];
        vector<int> order;
        if (root) {
            stack<int> dfs;
            dfs.push(root);
            unordered_set<int> seen;
            while (!dfs.empty()) {
                int u = dfs.top();
                dfs.pop();
                if (seen.insert(u).second) {
                    order.push_back(u);
                    for (auto &e : virtualTree[u]) {
                        if (!seen.count(e.first))
                            dfs.push(e.first);
                    }
                }
            }
        }

        reverse(order.begin(), order.end());
        unordered_map<int, long long> subSum;
        long long totalSum = 0;

        for (int x : nodes)
            if (mark[x] == 1)
                totalSum = (totalSum + x) % MOD;

        for (int u : order)
            subSum[u] = (mark[u] == 1 ? u : 0);

        long long result = 0;
        for (int u : order) {
            for (auto &edge : virtualTree[u]) {
                int v = edge.first;
                int w = edge.second;
                if (depth[v] > depth[u]) {
                    long long left = subSum[v];
                    long long right = (totalSum - left + MOD) % MOD;
                    long long contrib = ((left * right) % MOD * w) % MOD;
                    result = (result + contrib) % MOD;
                    subSum[u] = (subSum[u] + subSum[v]) % MOD;
                }
            }
        }

        cout << result << "\n";

        for (int x : all) {
            virtualTree[x].clear();
            mark[x] = 0;
        }
    }

    return 0;
}
