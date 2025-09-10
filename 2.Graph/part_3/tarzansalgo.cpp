#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tarjanSCC(int V, vector<int> adj[]) {
        vector<int> discovery(V, -1), lowtime(V, -1), inStack(V, 0);
        stack<int> st;
        int currtime = 0, sccCount = 0;

        function<void(int)> dfs = [&](int node) {
            discovery[node] = lowtime[node] = ++currtime;
            st.push(node);
            inStack[node] = 1;

            for (int &neigh : adj[node]) {
                if (discovery[neigh] == -1) {   // not visited
                    dfs(neigh);
                    lowtime[node] = min(lowtime[node], lowtime[neigh]);
                } 
                else if (inStack[neigh]) { // back edge
                    lowtime[node] = min(lowtime[node], discovery[neigh]);
                }
            }

            // if u is root of SCC
            if (lowtime[node] == discovery[node]) {
                sccCount++;
                while (true) {
                    int currnode = st.top(); st.pop();
                    inStack[currnode] = 0;
                    if (node == currnode) break;
                }
            }
        };

        for (int i = 0; i < V; i++) {
            if (discovery[i] == -1) dfs(i);
        }
        return sccCount;
    }
};

int main() {
    
}
