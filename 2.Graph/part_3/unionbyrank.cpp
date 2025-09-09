#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        else return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findParent(u), ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else{
            parent[ulp_v] = ulp_u;
            if(rank[ulp_u] == rank[ulp_v]) rank[ulp_u]++;
        }
    }
};

int main() {

    return 0;
}