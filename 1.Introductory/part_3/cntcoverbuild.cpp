#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> mpx, mpy;

        for(auto &it : buildings){
            int x = it[0], y = it[1];
            mpx[x].push_back(y);
            mpy[y].push_back(x);
        }

        for(auto &[a, b] : mpx) sort(b.begin(), b.end());
        for(auto &[a, b] : mpy) sort(b.begin(), b.end());

        int cnt = 0;
        for(auto &it : buildings){
            int x = it[0], y = it[1];
            vector<int> &yAtSameX = mpx[x], xAtSameY = mpy[y];

            bool hasleft = xAtSameY[0] < x;
            bool hasrght = x < xAtSameY.back();
            bool hastopp = yAtSameX[0] < y;
            bool hasbotm = y < yAtSameX.back();

            if(hasleft and hasrght and hasbotm and hastopp) cnt++;
        }

        return cnt;
    }
};

int main() {

    return 0;
}