#include <bits/stdc++.h>
using namespace std;

bool cancolor(int node, vector<int> &color, vector<int> adj[], int col){
    color[node] = col;

    for(auto &neigh: adj[node]){
        if(color[neigh] == -1){
            if(!cancolor(neigh, color, adj, !col)) return false;
        } else if(color[neigh] == col) return false;
    }

    return true;
}

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

    vector<int> color(m+1, -1);

    for(int i = 1; i <= m; i++){
        if(color[i] == -1){
            if(!cancolor(i, color, adj, 0)){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i = 1; i <= m; i++){
        cout<<color[i]+1<<" ";
    }
    return 0;
}