#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pair<int, long long>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1});
    vector<vector<long long>> distances(n + 1);
    vector<long long> result;
    
    while (!pq.empty() && result.size() < k) {
        auto [dist, node] = pq.top(); pq.pop();
        
        if (distances[node].size() >= k) {
            continue;
        }
        
        distances[node].push_back(dist);
        if (node == n) {
            result.push_back(dist);
            if (result.size() == k)  break;
            continue;
        }
        for (auto& [neighbor, cost] : graph[node]) {
            long long new_dist = dist + cost;
            
            if (distances[neighbor].size() < k) {
                pq.push({dist + cost, neighbor});
            }
        }
    }
    
    for(auto &it : result) cout<<it<<" ";
    
    return 0;
}