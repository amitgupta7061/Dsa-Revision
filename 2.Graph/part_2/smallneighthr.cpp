#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        for(auto it : edges){
            int u = it[0], v = it[1], w = it[2];
            dist[u][v] = dist[v][u] = w;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != 1e9 and dist[k][j] != 1e9 and dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int maxcity = -1, minreach = INT_MAX;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(dist[i][j] <= distanceThreshold) cnt++;
            }

            if(cnt < minreach){
                cnt = minreach;
                maxcity = i;
            } else if(cnt == minreach){
                maxcity = max(maxcity, i);
            }
        }
        return maxcity;
    }
};

int main() {

    return 0;
}