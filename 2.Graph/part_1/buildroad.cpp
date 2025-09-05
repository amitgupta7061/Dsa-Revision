#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) dfs(neigh, adj, visited);
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    vector<bool> visited(n+1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> reps;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            reps.push_back(i);
            dfs(i, adj, visited);
        }
    }

    int needroads = reps.size() - 1;
    cout << needroads << '\n';
    for (int i = 0; i < needroads; ++i) {
        cout << reps[i] << ' ' << reps[i + 1] << '\n';
    }

    return 0;
}
