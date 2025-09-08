#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, long>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int x = -1;
    for(int i = 1; i <= n; i++){
        x = -1;
        for (int u = 1; u <= n; u++) {
            for (auto &[v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    x = v;
                }
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
        for (int it : cycle) cout << it << " ";
        cout << "\n";
    }
    return 0;
}
