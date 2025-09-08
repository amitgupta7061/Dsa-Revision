#include <bits/stdc++.h>
using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int degree(int x, int y, vector<vector<int>>& board) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (inside(nx, ny) && board[nx][ny] == -1) cnt++;
    }
    return cnt;
}

bool knightsTour(int x, int y, vector<vector<int>>& board) {
    board[x][y] = 1;
    for (int step = 2; step <= 64; step++) {
        int bestDeg = 9, nextX = -1, nextY = -1;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (inside(nx, ny) && board[nx][ny] == -1) {
                int d = degree(nx, ny, board);
                if (d < bestDeg) {
                    bestDeg = d;
                    nextX = nx;
                    nextY = ny;
                }
            }
        }
        if (nextX == -1) return false; // no move possible
        board[nextX][nextY] = step;
        x = nextX; y = nextY;
    }
    return true;
}

int main() {
    int c, r;
    cin >> c >> r;
    r--; c--;

    vector<vector<int>> board(8, vector<int>(8, -1));

    knightsTour(r, c, board);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
