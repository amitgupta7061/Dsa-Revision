#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int n, int ind, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                             vector<string>& board, vector<vector<string>>& ans) {

        if (ind == n) {
            ans.push_back(board); return;
        }

        for (int j = 0; j < n; j++) {

            if (cols[j] || diag1[ind + j] || diag2[j - ind + n - 1]) continue;
            board[ind][j] = 'Q';
            cols[j] = diag1[ind + j] = diag2[j - ind + n - 1] = true;

            dfs(n, ind + 1, cols, diag1, diag2, board, ans);
            cols[j] = diag1[ind + j] = diag2[j - ind + n - 1] = false;
            board[ind][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<bool> col(n), diag1(2*n-1), diag2(2*n-1);
        vector<string> board(n, string(n, '.'));
        dfs(n, 0, col, diag1, diag2, board, result);
        return result;
    }
};

int main() {

    return 0;
}