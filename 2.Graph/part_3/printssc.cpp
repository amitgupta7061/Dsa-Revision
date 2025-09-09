#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs1(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (int neigh : adj[node]) {
            if (!vis[neigh]) dfs1(neigh, adj, vis, st);
        }
        st.push(node);
    }

    void dfs2(int node, vector<int> adjT[], vector<int>& vis, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);
        for (int neigh : adjT[node]) {
            if (!vis[neigh]) dfs2(neigh, adjT, vis, component);
        }
    }

    vector<vector<int>> kosaraju(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: DFS order (finish times)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs1(i, adj, vis, st);
        }

        // Step 2: Transpose graph
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            for (int neigh : adj[i]) {
                adjT[neigh].push_back(i);
            }
        }

        // Step 3: DFS on transpose graph
        fill(vis.begin(), vis.end(), 0);
        vector<vector<int>> sccs;

        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!vis[node]) {
                vector<int> component;
                dfs2(node, adjT, vis, component);
                sccs.push_back(component);
            }
        }

        return sccs;
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];

    // Example graph
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0,3};
    adj[3] = {4};

    Solution sol;
    vector<vector<int>> sccs = sol.kosaraju(V, adj);

    cout << "Strongly Connected Components:\n";
    for (auto &comp : sccs) {
        for (int node : comp) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
