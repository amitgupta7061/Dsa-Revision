#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool onSameRegion(vector<int> &fst, vector<int> &scd){
        long long dx = fst[0] - scd[0], dy = fst[1] - scd[1], r = fst[2];
        return dx * dx + dy * dy <= r * r;
    }
    void dfs(vector<vector<int>> &graph, int src, int &cnt, vector<int> &visited){
        cnt++;
        visited[src] = true;

        for(int &neigh : graph[src]){
            if(!visited[neigh]) dfs(graph, neigh, cnt, visited);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && onSameRegion(bombs[i], bombs[j])) graph[i].push_back(j);
            }
        }

        int maxCnt = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            vector<int> visited(n, false);
            dfs(graph, i, cnt, visited);
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};

int main() {

    return 0;
}