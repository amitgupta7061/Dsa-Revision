#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int sx = knightPos[0] - 1, sy = knightPos[1] - 1;
        int tx = targetPos[0] - 1, ty = targetPos[1] - 1;

        if (sx == tx && sy == ty) return 0;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int,int>> moves = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

        queue<tuple<int, int, int>> q;
        q.push({sx, sy, 0});
        visited[sx][sy] = true;

        while (!q.empty()) {
            auto [x, y, steps] = q.front(); q.pop();

            for (auto &m : moves) {
                int nx = x + m.first, ny = y + m.second;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    if (nx == tx && ny == ty) return steps + 1;

                    visited[nx][ny] = true;
                    q.push({nx, ny, steps + 1});
                }
            }
        }
        return -1;
    }
};
  

int main() {

    return 0;
}