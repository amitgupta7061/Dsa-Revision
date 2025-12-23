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
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unity(int u, int v){
        int ulpu = findParent(u), ulpv = findParent(v);
        if(ulpu == ulpv) return;
        if(size[ulpu] < size[ulpv]){
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        } else {
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet D(n);
        int connectedComp = 0, extraEdge = 0;
        for(auto conn : connections){
            if(D.findParent(conn[0]) == D.findParent(conn[1])) extraEdge++;
            else D.unity(conn[0], conn[1]);
        }
        for(int i = 0; i < n; i++) if(D.findParent(i) == i) connectedComp++;
        return connectedComp-1 <= extraEdge ? connectedComp-1 : -1;
    }
};

int main() {

    return 0;
}