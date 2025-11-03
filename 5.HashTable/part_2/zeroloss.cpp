#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> lossesCount;

        for (auto m : matches) {
            int winner = m[0], loser = m[1];
            if (!lossesCount.count(winner)) lossesCount[winner] = 0;
            lossesCount[loser]++;
        }

        for (auto& [player, cnt] : lossesCount)
            if (cnt < 2) ans[cnt].push_back(player);
        return ans;
    }
};

int main() {

    return 0;
}