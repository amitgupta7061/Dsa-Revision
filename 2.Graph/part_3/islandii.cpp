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

    void unity(int u, int v){
        int ulp_u = findParent(u), ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } else{
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int,int>>& positions) {
        DisjointSet d(m * n);
        vector<int> result, isLand(m * n, -1), directions = {0, 1, 0, -1, 0};
        int count = 0;

        for(auto &[r, c] : positions){

            int ind = r * n + c;
            if(isLand[ind] != -1){  // already land
                result.push_back(count); continue;
            }
            isLand[ind] = true; // make it land
            count++;

            for(int i = 0; i < 4; i++){
                int nr = r + directions[i], nc = c + directions[i+1], nind = nr * n + nc;
                if(nr >= 0 and nc >= 0 and nr < m and nc < n and isLand[nind] != -1){
                    int p1 = d.findParent(ind), p2 = d.findParent(nind);
                    if(p1 != p2){
                        d.unity(p1, p2); count--;
                    }
                }
            }

            result.push_back(count);
        }
        return result;
    }     
};

int main() {

    return 0;
}