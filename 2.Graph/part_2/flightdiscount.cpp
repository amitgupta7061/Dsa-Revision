#include <bits/stdc++.h>
using namespace std;


int main() {

    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> adj[v+1];
    while(e--){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    vector<vector<long long>> dist(v+1, vector<long long>(2, 1e18));
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;

    pq.push({0, 1, 0}); // cost node used
    dist[1][0] = 0;

    while(pq.size()){
        auto [cost, node, used] = pq.top(); pq.pop();
        if(cost > dist[node][used]) continue;

        for(auto [neigh, weight] : adj[node]){
            if(dist[neigh][used] > dist[node][used] + weight){
                dist[neigh][used] = dist[node][used] + weight;
                pq.push({dist[neigh][used], neigh, used});
            }

            if(used == 0){
                long long discount = dist[node][0] + weight / 2;
                if(dist[neigh][1] > discount){
                    dist[neigh][1] = discount;
                    pq.push({discount, neigh, 1});
                } 
            }
        }
    }

    cout << dist[v][1] << '\n';

    return 0;
}