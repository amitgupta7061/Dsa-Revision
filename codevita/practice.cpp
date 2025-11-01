
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), result = 0;
        DisjointSet D(n * n);
        vector<int> directions = {0, 1, 0, -1, 0};
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 0) continue;
                for(int d = 0; d < 4; d++){
                    int nr = r + directions[d], nc = c + directions[d+1];
                    if(nr >= 0 and nc >= 0 and nr < n and nc < n and grid[nr][nc]){
                        D.unity(r * n + c, nr * n + nc);
                    }
                }
            }
        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 1) continue;
                set<int> components;
                for(int d = 0; d < 4; d++){
                    int nr = r + directions[d], nc = c + directions[d+1];
                    if(nr >= 0 and nc >= 0 and nr < n and nc < n and grid[nr][nc]){
                        components.insert(D.findParent(nr * n + nc));
                    }
                }

                int totalsize = 0;
                for(auto it : components) totalsize += D.size[it];
                result = max(result, totalsize + 1);
            }
        }

        for(int i = 0; i < n*n; i++){
            result = max(result, D.size[D.findParent(i)]);
        }
        
        return result;
    }
};

int main() {

    return 0;
}