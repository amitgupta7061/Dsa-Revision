#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int,int>>> st;  // to store unique shapes

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int,int>> shape;
                    dfs(i, j, grid, shape, i, j);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }

private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int,int>>& shape, int row, int col) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) 
            return;

        grid[i][j] = 0;
        shape.push_back({i - row, j - col}); // relative position

        dfs(i + 1, j, grid, shape, row, col);
        dfs(i - 1, j, grid, shape, row, col);
        dfs(i, j + 1, grid, shape, row, col);
        dfs(i, j - 1, grid, shape, row, col);
    }
};



int main() {

    return 0;
}