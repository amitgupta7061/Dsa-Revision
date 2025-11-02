#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));

        for (auto &g : guards) grid[g[0]][g[1]] = 'G';
        for (auto &w : walls) grid[w[0]][w[1]] = 'W';

        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

        for (auto &g : guards) {
            int r = g[0], c = g[1];
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                while (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] != 'W' && grid[nr][nc] != 'G') {
                    if (grid[nr][nc] == '.') grid[nr][nc] = 'S'; // S = seen
                    nr += dr[d];
                    nc += dc[d];
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.') count++;
            }
        }

        return count;
    }
};


int main() {

    return 0;
}