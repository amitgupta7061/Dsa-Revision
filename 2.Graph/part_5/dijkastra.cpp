#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int, int>> adj[V];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> result(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({src, 0});
        result[src] = 0;

        while(pq.size()){
            int curr = pq.top().first, dist = pq.top().second; pq.pop();

            for(auto it : adj[curr]){
                int neigh = it.first, weight = it.second;
                if(dist + weight < result[neigh]){
                    result[neigh] = dist + weight;
                    pq.push({neigh, result[neigh]});
                }
            }
        }
        for(int i = 0; i < V; i++){
            if(result[i] == INT_MAX) result[i] = -1;
        }

        return result;
    }
};

int main() {

    return 0;
}