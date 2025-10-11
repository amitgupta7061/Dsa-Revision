#include <bits/stdc++.h>
using namespace std;

// Brute force
class Solution {
public:
    int cntAllPath(int src, int f, vector<int> adj[], vector<int> &visited, int val, vector<int> &vals, int &cnt){
        if(src != f && vals[src] == val) {
            cnt++;
        }

        visited[src] = true;
        for(auto &neigh : adj[src]){
            if(!visited[neigh] && vals[neigh] <= val){
                cntAllPath(neigh, f, adj, visited, val, vals, cnt);
            }
        }
        visited[src] = false; 
        return 0;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        unordered_map<int, int> valmap;
        for(auto it : vals) valmap[it]++;
        vector<int> adj[n];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = 0;

        set<pair<int,int>> pairs;
        for(int i = 0; i < n; i++){
            vector<int> visited(n, 0);
            if(valmap[vals[i]] > 1)
                cntAllPath(i, i, adj, visited, vals[i], vals, cnt);
        }

        return cnt/2 + n;
    }
};

// Optimal
class Solution {
public:
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        map<int, vector<int>> nodeByVal;
        for(int i = 0; i < n; i++) nodeByVal[vals[i]].push_back(i);

        DisjointSet d(n);
        int result = 0;

        for(auto &[val, nodes] : nodeByVal){
            for(int &node : nodes){
                for(int &neigh : adj[node]){
                    if(vals[neigh] <= val) d.unite(node, neigh);
                }
            }

            unordered_map<int, int> components;
            for(int &node : nodes) components[d.findParent(node)]++;

            for (auto &[root, cnt] : components) result += cnt * (cnt - 1) / 2;
        }

        return result + n;
    }
};


int main() {

    return 0;
}