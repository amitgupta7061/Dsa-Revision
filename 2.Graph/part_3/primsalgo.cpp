#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for(auto &it : edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0}); // weight, node

        int sum = 0;

        while(pq.size()){
            auto [weight, node] = pq.top(); pq.pop();
            if(visited[node]) continue;
            visited[node] = true;
            sum += weight;

            for(auto &[neigh, nweight] : adj[node]){
                if(!visited[neigh]){
                    pq.push({nweight, neigh});
                }
            }
        }

        return sum;
    }
};

int main() {

    return 0;
}