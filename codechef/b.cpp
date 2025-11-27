#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, w;
            cin >> u >> w;
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        
        vector<int> result, visited(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        visited[1] = true;
        result.push_back(v[1]);

        for (int neigh : adj[1]) {
            pq.push({v[neigh], neigh});
        }
        
        while (!pq.empty()) {
            auto [val, node] = pq.top(); pq.pop();
            if (visited[node]) continue;

            visited[node] = true;
            result.push_back(v[node]);
    
            for (int neigh : adj[node]) {
                if (!visited[neigh]) {
                    pq.push({v[neigh], neigh});
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << result[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}