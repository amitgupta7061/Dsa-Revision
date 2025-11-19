#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0), timeIn(n, -1);
        int timer = 1, ans = -1;

        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            int node = i;
            unordered_map<int, int> step;
            while(node != -1 && !visited[node]) {
                visited[node] = 1;
                step[node] = timer++;
                node = edges[node];
            }

            if(node != -1 && step.count(node)) {
                ans = max(ans, timer - step[node]);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int result = -1;
    void dfs(int u, vector<int>& edges, vector<int> &visited, vector<int>& dist, vector<int> &inRec) {
        if(u != -1) {
            visited[u] = true;
            inRec[u] = true;
            
            int v = edges[u];
            if(v != -1 && !visited[v]) {
                dist[v] = dist[u] + 1;
                dfs(v, edges, visited, dist, inRec);
            } else if(v != -1 && inRec[v] == true) {
                result = max(result, dist[u] - dist[v] +1);
            }
        
            inRec[u] = false;
        }  
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<int> visited(n, 0), dist(n, 1), inRec(n, 0);
        for(int i = 0 ; i<n; i++) {
            if(!visited[i]) dfs(i, edges, visited, dist, inRec);
        }
        
        return result;
    }
};

int main() {

    return 0;
}