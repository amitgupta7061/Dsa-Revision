#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
        for (auto it : edgeList) {
            int u = it[0], v = it[1], w = it[2];
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = min(graph[v][u], w);
        }

        for (int i = 0; i < n; i++) graph[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
                }
            }
        }
        vector<bool> result;
        for(auto &it : queries){
            int u = it[0], v = it[1], w = it[2];
            if(graph[u][v] < w) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};



bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

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
        int ulpU = findParent(u), ulpV = findParent(v);
        if(ulpU == ulpV) return;

        if(size[ulpU] < size[ulpV]){
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        } else{
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }
};

class Solution{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), cmp);

        int qn = queries.size();
        vector<int> idx(qn);
        iota(idx.begin(), idx.end(), 0);
        for(auto it : idx) 
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i][2] < queries[j][2];
        });

        DisjointSet d(n);
        vector<bool> result(qn, false);

        int edgeIndex = 0;
        for(int i = 0; i < qn; i++) {
            int qu = queries[idx[i]][0], qv = queries[idx[i]][1], qw = queries[idx[i]][2];

            while(edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < qw) {
                int u = edgeList[edgeIndex][0], v = edgeList[edgeIndex][1];
                d.unity(u, v);
                edgeIndex++;
            }

            if(d.findParent(qu) == d.findParent(qv)) result[idx[i]] = true;
        }

        return result;
    }
};



int main() {

    return 0;
}