#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n, nonobstacle;
    vector<int> directions = {0, 1, 0, -1, 0};
    void f(vector<vector<int>> &grid, int r, int c, int cnt, int &result){
        if(r < 0 or c < 0 or r >= m or c >= n or grid[r][c] == -1) return;
        if(grid[r][c] == 2){
            if(cnt == nonobstacle) result++;
            return;
        }
        cnt++;
        grid[r][c] = -1;
        for(int d = 0; d < 4; d++){
            int nr = r + directions[d], nc = c + directions[d+1];
            f(grid, nr, nc, cnt, result);
        }
        grid[r][c] = 0;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx, starty;
        m = grid.size(), n = grid[0].size(), nonobstacle = 2;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    startx = i, starty = j;
                }else if(grid[i][j] == 0) nonobstacle++;
            }
        }

        int result = 0;
        f(grid, startx, starty, 1, result);
        return result;
    }
};

int main() {

    return 0;
}