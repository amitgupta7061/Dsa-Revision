#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n, 1);
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
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet D(n);
        int extraedge = 0, connectedcomp = 0;

        for(auto &it : connections){
            int u = it[0], v = it[1];
            if(D.findParent(u) != D.findParent(v)){
                D.unionbysize(u, v);
            } else extraedge++;
        }
        for(int i = 0; i < n; i++){
            if(D.parent[i] == i) connectedcomp++;
        }
        return connectedcomp-1 <= extraedge? connectedcomp-1 : -1;
    }
};

int main() {

    return 0;
}