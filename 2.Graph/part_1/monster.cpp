#include <bits/stdc++.h>
using namespace std;

struct Node {
    int r, c, t;
};

const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vector<char> dirChar = {'R', 'D', 'U', 'L'};

void fillMonsterTime(vector<vector<int>> &monsterTime, queue<pair<int, int>> &mq, vector<vector<char>> &mat){
    while(!mq.empty()){
        auto [r, c] = mq.front(); mq.pop();

        for(auto d : dir){
            int nr = r + d.first, nc = c + d.second;
            if(nr < 0 || nc < 0 || nr >= mat.size() || nc >= mat[0].size()) continue;
            if(mat[nr][nc] == '#' || monsterTime[nr][nc] != -1) continue;
            monsterTime[nr][nc] = monsterTime[r][c] + 1;
            mq.push({nr, nc});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    pair<int, int> start;

    queue<pair<int, int>> mq;
    vector<vector<int>> monsterTime(n, vector<int>(m, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'A') start = {i, j};
            else if(mat[i][j] == 'M'){
                mq.push({i,j});
                monsterTime[i][j] = 0;
            }
        }
    }

    fillMonsterTime(monsterTime, mq, mat);

    vector<vector<int>> playerTime(n, vector<int>(m, -1));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveDir(n, vector<char>(m));

    queue<Node> q;
    q.push({start.first, start.second, 0});
    playerTime[start.first][start.second] = 0;

    pair<int,int> end = {-1,-1};

    while(!q.empty()){
        auto [r, c, t] = q.front(); q.pop();

        if(r == 0 || c == 0 || r == n-1 || c == m-1){
            end = {r, c};
            break;
        }

        for(int k = 0; k < 4; k++){
            int nr = r + dir[k].first, nc = c + dir[k].second;
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(mat[nr][nc] == '#' || playerTime[nr][nc] != -1) continue;

            int nt = t + 1;
            if(monsterTime[nr][nc] != -1 && nt >= monsterTime[nr][nc]) continue;

            playerTime[nr][nc] = nt;
            parent[nr][nc] = {r,c};
            moveDir[nr][nc] = dirChar[k];
            q.push({nr, nc, nt});
        }
    }

    if(end.first == -1){
        cout << "NO\n";
    } else {
        cout << "YES\n";

        string path;
        while(end != start){
            path.push_back(moveDir[end.first][end.second]);
            end = parent[end.first][end.second];
        }
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        cout << path << "\n";
    }

    return 0;
}
