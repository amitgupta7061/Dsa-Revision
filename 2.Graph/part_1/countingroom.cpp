#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int r, int c, vector<vector<char>> &mat){
    mat[r][c] = '#';

    for(auto &it : direction){
        int nr = r + it.first, nc = c + it.second;
        if(nr < 0 or nc < 0 or nr >= mat.size() or nc >= mat[0].size() or mat[nr][nc] == '#') continue;
        dfs(nr, nc, mat);
    }
}

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<char>> mat(m, vector<char>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    int cnt = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == '.'){
                ++cnt;
                dfs(i, j, mat);
            }
        }
    }
    
    cout<<cnt;


    return 0;
}