#include <bits/stdc++.h>
using namespace std;

int startnode, endnode;

bool cyclefound(int node, vector<int> &visited, vector<int> &parent, vector<int> &samerec, vector<pair<int,int>> adj[]){
    visited[node] = 1;
    samerec[node] = 1;

    for(auto &[neigh, len] : adj[node]){
        if(!visited[neigh]){
            parent[neigh] = node;
            if(cyclefound(neigh, visited, parent, samerec, adj)) return true;
        }
        else if(samerec[neigh]){
            startnode = node;
            endnode = neigh;
            return true;
        }
    }
    samerec[node] = 0;
    return false;
}

int main() {

    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> adj[v+1];
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    vector<int> visited(v+1, 0), samerec(v+1, 0), parent(v+1, -1);
    bool found = false;
    for(int i = 1; i <= v; i++){
        if(!visited[i]){
            if(cyclefound(i, visited, parent, samerec, adj)){
                found = true; break;
            }
        }
    }

    if(found){
        cout<<"YES\n";
        vector<int> cycle;
        cycle.push_back(endnode);
        while(startnode != endnode){
            cycle.push_back(startnode);
            startnode = parent[startnode];
        }
        cycle.push_back(endnode);

        for(auto &it : cycle) cout<<it<<" ";
    } else {
        cout<<"No";
    }

    return 0;
}