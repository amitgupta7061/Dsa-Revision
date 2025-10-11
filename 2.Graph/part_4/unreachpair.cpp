#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unite(int u, int v){
        int ulp_u = findParent(u), ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet d(n);

        for(auto &it : edges) d.unite(it[0], it[1]);
        
        unordered_map<int, int> component;
        for(auto it : d.parent) component[it]++;

        long long total = 0, sum = 0;
        for (auto it : component) sum += it.second;
        for (auto it : component) total += 1LL * it.second * (sum - it.second);

        return total /= 2;
    }
};

int main() {

    return 0;
}