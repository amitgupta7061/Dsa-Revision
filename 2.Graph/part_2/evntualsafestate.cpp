#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> outdegree(n, 0);

        // Build reverse graph and outdegree count
        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();
            for (int v : graph[u]) {
                rev[v].push_back(u);  // reverse edge
            }
        }

        queue<int> q;
        vector<bool> isSafe(n, false);

        // Start with terminal nodes (outdegree == 0)
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            isSafe[node] = true;

            // For each predecessor in the reversed graph
            for (int prev : rev[node]) {
                if (--outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        // Collect safe nodes
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) result.push_back(i);
        }

        return result;
    }
};

int main() {

    return 0;
}