#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DfS(vector<int> adj[], vector<int> &visited, vector<int> &samRecursion, int node){
        visited[node] = 1; samRecursion[node] = 1;
        for(auto neighbour : adj[node]){
            if(not visited[neighbour]){
                if(DfS(adj, visited, samRecursion, neighbour)) return true;
            }
            else if(samRecursion[neighbour]) return true;
        }
        samRecursion[node] = 0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> visited(v, 0), samRecursion(v, 0);
        for(int i = 0; i < v; i++){
            if(not visited[i])
                if(DfS(adj, visited, samRecursion, i)) return true;
        }
        return false;
    }
};

class Solution{
public:
    bool isCyclic(int vertex, vector<vector<int>> &edges) {
        vector<int> adj[vertex], Indegree(vertex,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            Indegree[it[1]]++;
        }
            
        queue<int> q;
        for(int i = 0; i < vertex; i++) {
            if(Indegree[i]==0) q.push(i);
        }

        int cnt=0;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            cnt++;
            for(int neigh : adj[node]) {
                if(--Indegree[neigh] == 0) q.push(neigh);
            }
        }
        return cnt != vertex;
    }
};

int main() {

    return 0;
}