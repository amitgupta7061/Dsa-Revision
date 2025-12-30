#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (r < 3 || c < 3) return 0;
        
        int ans = 0;
        for (int i = 0; i + 2 < r; i++) {
            for (int j = 0; j + 2 < c; j++) {
                if (grid[i+1][j+1] != 5) continue;  // center check
                vector<int> freq(10, 0);
                bool ok = true;
    
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        int v = grid[x][y];
                        if (v < 1 || v > 9 || freq[v]) {
                            ok = false;
                            break;
                        }
                        freq[v] = 1;
                    }
                    if (!ok) break;
                }
                if (!ok) continue;
                
                for (int x = i; x < i + 3; x++) {  // row check
                    if (grid[x][j] + grid[x][j+1] + grid[x][j+2] != 15) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                
                for (int y = j; y < j + 3; y++) {   // col check
                    if (grid[i][y] + grid[i+1][y] + grid[i+2][y] != 15) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                
                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != 15) continue;
                if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != 15) continue;
                
                ans++;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}