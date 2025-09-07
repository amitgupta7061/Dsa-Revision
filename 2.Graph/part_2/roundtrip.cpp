#include <bits/stdc++.h>
using namespace std;

int startnode, endnode;

bool DFS(int node, vector<int> &visited, vector<int> &parent, vector<int> adj[]){
    visited[node] = 1;

    for(auto &neigh : adj[node]){
        if(!visited[neigh]){
            parent[neigh] = node;
            if(DFS(neigh, visited, parent, adj)) return true;
        } else if(neigh != parent[node]){
            startnode = node;
            endnode = neigh;
            return true;
        }
    }
    return false;
}

int main() {

    int v, e;
    cin >> v >> e;

    vector<int> adj[v+1];
    while(e--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(v+1, 0), parent(v+1, -1);
    bool found = false;

    for(int i = 1; i <= v; i++){
        if(!visited[i]){
            if(DFS(i, visited, parent, adj)){
                found = true;
                break;
            }
        }
    }

    if(!found){
        cout<<"IMPOSSIBLE";
    } else {
        vector<int> cycle;
        cycle.push_back(endnode);

        while(startnode != endnode){
            cycle.push_back(startnode);
            startnode = parent[startnode];
        }

        cycle.push_back(endnode);

        cout << cycle.size() << "\n";
        for (auto x : cycle) cout << x << " ";
    }


    return 0;
}