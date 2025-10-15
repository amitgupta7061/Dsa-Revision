#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& Prob, int src, int dest) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            double w = Prob[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, src});
        vector<double> maxProb(n, 0.0);
        maxProb[src] = 1.0;

        while(pq.size()){
            auto [currentProb, node] = pq.top(); pq.pop();

            for(auto [neigh, edgeProb] : adj[node]){
                double newProb = currentProb * edgeProb;
                if(newProb > maxProb[neigh]){
                    maxProb[neigh] = newProb;
                    pq.push({newProb, neigh});
                }
            }
        }
        return maxProb[dest];
    }
};


int main() {

    return 0;
}