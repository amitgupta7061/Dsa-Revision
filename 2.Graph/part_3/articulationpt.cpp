#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> lowtime(n, 0), discovery(n, 0), isAP(n, 0);
        int currtime = 0;

        function<void(int,int)> dfs = [&](int node, int parent) {
            discovery[node] = lowtime[node] = ++currtime;
            int children = 0;

            for (auto neigh : adj[node]) {
                if (neigh == parent) continue;

                if (discovery[neigh] == 0) { // not visited
                    children++;
                    dfs(neigh, node);
                    lowtime[node] = min(lowtime[node], lowtime[neigh]);

                    if (parent != -1 && lowtime[neigh] >= discovery[node]) {
                        isAP[node] = 1;
                    }
                } else {
                    lowtime[node] = min(lowtime[node], discovery[neigh]);
                }
            }

            if (parent == -1 && children > 1) {
                isAP[node] = 1;
            }
        };

        for (int i = 0; i < n; i++) {
            if (discovery[i] == 0) dfs(i, -1);
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (isAP[i]) result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};

int main() {
    Solution sol;
    int n = 7;
    vector<int> adj[] = {
        {1,2,3},   // 0
        {0},       // 1
        {0,3,4,5}, // 2
        {2,0},     // 3
        {2,6},     // 4
        {2,6},     // 5
        {4,5}      // 6
    };

    vector<int> result = sol.articulationPoints(n, adj);
    for (auto it : result) cout << it << " ";
    return 0;
}
