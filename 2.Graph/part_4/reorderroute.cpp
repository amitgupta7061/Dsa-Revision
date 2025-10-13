#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for(auto &it : connections){
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }

        vector<int> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int count = 0;

        while(q.size()){
            int node = q.front(); q.pop();
            for(auto &[neigh, conn] : adj[node]){
                if(visited[neigh]) continue;
                visited[neigh] = true;
                if(conn == 1) count++;
                q.push(neigh);
            }
        }
        return count;
    }
};

int main() {

    return 0;
}