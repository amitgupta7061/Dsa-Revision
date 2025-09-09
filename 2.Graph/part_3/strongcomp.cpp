#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st, bool stackopr) {
        visited[node] = 1;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) dfs(neigh, adj, visited, st, true);
        }
        if(stackopr) st.push(node);
    }

    int kosaraju(vector<vector<int>> adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) { // dfs for fill stack
            if (!visited[i]) dfs(i, adj, visited, st, true);
        }

        vector<vector<int>> adjT(V);  // Transpose of graph
        for (int i = 0; i < V; i++) {
            for (int &neigh : adj[i]) {
                adjT[neigh].push_back(i);
            }
        }

        fill(visited.begin(), visited.end(), 0);
        int sccCount = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!visited[node]) {
                sccCount++;
                dfs(node, adjT, visited, st, false);
            }
        }

        return sccCount;
    }
};

int main() {
    
}
