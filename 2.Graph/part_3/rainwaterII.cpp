#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pairr;

class Solution {
public:
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pairr, vector<pairr>, greater<pairr>> pq;  // height, row, col
        int m = heightMap.size(), n = heightMap[0].size(), water = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < n; i++){  // 1st row and last row
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[m-1][i], {m-1, i}});
            visited[0][i] = true; visited[m-1][i] = true;
        }
        for(int i = 1; i < m-1; i++){  // 1st col and last col
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = true; visited[i][n-1] = true;
        }
        while(pq.size()){
            auto curr = pq.top(); pq.pop();
            int height = curr.first, row = curr.second.first, col = curr.second.second;
            for(auto &dir : direction){
                int newRow = row + dir[0], newCol = col + dir[1];
                if(newRow >= 0 and newRow < m and newCol >= 0 and newCol < n and !visited[newRow][newCol]){
                    water += max(height - heightMap[newRow][newCol], 0);
                    pq.push({max(height, heightMap[newRow][newCol]), {newRow, newCol}});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return water;
    }
};

int main() {

    return 0;
}