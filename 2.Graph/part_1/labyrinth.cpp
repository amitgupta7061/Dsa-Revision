#include <bits/stdc++.h>
using namespace std;

const vector<tuple<int, int, char>> direction = {
    {0, 1, 'R'}, {1, 0, 'D'}, {-1, 0, 'U'}, {0, -1, 'L'}
};

bool is_valid(int r, int c, int m, int n, const vector<vector<char>> &mat, const vector<vector<bool>> &visited) {
    return r >= 0 && c >= 0 && r < m && c < n && mat[r][c] != '#' && !visited[r][c];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> mat(m, vector<char>(n));
    pair<int, int> start, end;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A') start = {i, j};
            if (mat[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n, {-1, -1}));
    vector<vector<char>> move_dir(m, vector<char>(n));
    
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (make_pair(r, c) == end) {
            found = true;
            break;
        }

        for (auto &d : direction) {
            int nr = r + get<0>(d), nc = c + get<1>(d);
            char dir = get<2>(d);

            if (is_valid(nr, nc, m, n, mat, visited)) {
                visited[nr][nc] = true;
                parent[nr][nc] = {r, c};
                move_dir[nr][nc] = dir;
                q.push({nr, nc});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        string path = "";
        while (end != start) {
            char dir = move_dir[end.first][end.second];
            path += dir;
            end = parent[end.first][end.second];
        }
        reverse(path.begin(), path.end());

        cout << "YES\n";
        cout << path.size() << "\n";
        cout << path << "\n";
    }

    return 0;
}
