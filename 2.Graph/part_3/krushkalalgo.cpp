#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:    
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n ,1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionbysize(int u, int v){
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

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        DisjointSet D(V);
        int sum = 0;
        sort(edges.begin(), edges.end(), cmp);
        for(auto &it : edges){
            int u = it[0], v = it[1], w = it[2];
            if(D.findParent(u) != D.findParent(v)){
                sum += w;
                D.unionbysize(u, v);
            }
        }
        return sum;
    }
};

int main() {

    return 0;
}