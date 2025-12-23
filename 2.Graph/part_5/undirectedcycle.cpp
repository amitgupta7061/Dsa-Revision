#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, int parent){
        visited[node] = true;
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                if(dfs(adj, neigh, visited, node)) return true;
            } else if(neigh != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(adj, i, visited, -1)) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool bfs(vector<vector<int>> &adj, int node, vector<bool> &visited){
        visited[node] = true;
        queue<pair<int, int>> q;
        q.push({node, -1});
        while(q.size()){
            auto [node, parent] = q.front(); q.pop();
            for(int neigh : adj[node]){
                if(!visited[neigh]){
                    visited[neigh] = true;
                    q.push({neigh, node});
                } else if(neigh != parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(bfs(adj, i, visited)) return true;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}