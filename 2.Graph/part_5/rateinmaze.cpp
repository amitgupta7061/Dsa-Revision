#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<vector<int>> &maze, int r, int c, string path, vector<string> &result, int n){
        if(r < 0 or c < 0 or r >= n or c >= n or maze[r][c] == 0) return;
        if(r == n-1 and c == n-1){
            result.push_back(path); return;
        }
        maze[r][c] = 0;
        f(maze, r+1, c, path+'D', result, n);
        f(maze, r, c-1, path+'L', result, n); 
        f(maze, r, c+1, path+'R', result, n);  
        f(maze, r-1, c, path+'U', result, n);
        maze[r][c] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> result;
        int n = maze.size();
        f(maze, 0, 0, "", result, n);
        return result;
    }
};

int main() {

    return 0;
}