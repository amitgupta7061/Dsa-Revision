#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n], lowtime(n, 0), discovery(n, 0);
        for(auto &it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> criticaledge;
        int currtime = 0;

        function<void(int, int)> f = [&](int node, int parent){
            lowtime[node] = discovery[node] = ++currtime;

            for(auto &neigh : adj[node]){
                if(neigh == parent) continue;
                if(discovery[neigh] == 0){// not visited
                    f(neigh, node);
                    lowtime[node] = min(lowtime[node], lowtime[neigh]);

                    if(lowtime[neigh] > discovery[node]){
                        criticaledge.push_back({node, neigh});
                    }
                } else{
                    lowtime[node] = min(lowtime[node], lowtime[neigh]);
                }
            }
        };

        f(0, -1);
        return criticaledge;
    }
};

int main() {

    return 0;
}