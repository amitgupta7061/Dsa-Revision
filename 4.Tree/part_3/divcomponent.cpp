#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = 0;
    int f(int node, int parent, vector<vector<int>> &adj, vector<int> &val, int k){
        long long sum = val[node];

        for (int &neigh : adj[node]) {
            if (neigh == parent) continue;
            sum += f(neigh, node, adj, val, k);
        }
        if (sum % k == 0) {
            result++; return 0;
        }
        return sum % k;
        
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        f(0, -1, adj, values, k);
        return result;
    }
};

int main() {

    return 0;
}