#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        vector<int> degree(n + 1, 0);

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        vector<int> levcnt(n + 1, 0), depth(n + 1, 0), visited(n + 1, 0);
        
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        depth[1] = 1;
        levcnt[1] = 1;

        while (q.size()) {
            int u = q.front(); q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    depth[v] = depth[u] + 1;
                    levcnt[depth[v]]++;
                    q.push(v);
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i <= n; ++i) {
            if (levcnt[i] > maxi) maxi = levcnt[i];
        }

        int star = 0;
        for (int i = 1; i <= n; ++i) {
            int req = i == 1 ? degree[i] + 1 : degree[i];
            if (req > star) star = req;
        }

        cout << max(maxi, star) << "\n";
    }
    return 0;
}