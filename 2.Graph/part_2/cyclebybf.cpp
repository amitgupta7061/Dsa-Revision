#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int x = -1;
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // ensure x is inside the cycle
        for (int i = 0; i < n; i++) {
            x = parent[x];
        }

        vector<int> cycle;
        int cur = x;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != x);
        cycle.push_back(x);

        reverse(cycle.begin(), cycle.end());
        for (int node : cycle) cout << node << " ";
        cout << "\n";
    }
    return 0;
}
