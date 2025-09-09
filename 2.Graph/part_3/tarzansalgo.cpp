#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tarjanSCC(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, -1), inStack(V, 0);
        stack<int> st;
        int timer = 0, sccCount = 0;

        function<void(int)> dfs = [&](int u) {
            disc[u] = low[u] = ++timer;
            st.push(u);
            inStack[u] = 1;

            for (int v : adj[u]) {
                if (disc[v] == -1) {   // not visited
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                } 
                else if (inStack[v]) { // back edge
                    low[u] = min(low[u], disc[v]);
                }
            }

            // if u is root of SCC
            if (low[u] == disc[u]) {
                sccCount++;
                while (true) {
                    int node = st.top(); st.pop();
                    inStack[node] = 0;
                    if (node == u) break;
                }
            }
        };

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) dfs(i);
        }
        return sccCount;
    }
};

int main() {
    
}
