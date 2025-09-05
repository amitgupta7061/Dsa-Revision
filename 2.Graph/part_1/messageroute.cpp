#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> adj[m+1];
    while(n--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(m+1, 0), dist(m+1, INT_MAX), parent(m+1, -1);

    queue<int> q;
    q.push(1);
    visited[1] = true;
    dist[1] = 0;

    while(!q.empty()){
        int node = q.front(); q.pop();

        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                dist[neigh] = dist[node] + 1;
                parent[neigh] = node;
                visited[neigh] = 1;
                q.push(neigh);
            }
        }
    }

    if(dist[m] == INT_MAX){
        cout << "IMPOSSIBLE";
    } else {
        vector<int> path;
        for(int curr = m; curr != -1; curr = parent[curr])
            path.push_back(curr);

        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for(auto it : path) cout << it << " ";
    }

    return 0;
}
