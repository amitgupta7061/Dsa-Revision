#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prevOnes = 0;

        for (const string& row : bank) {
            int ones = ranges::count(row, '1');
            if (ones > 0) {
                ans += prevOnes * ones;
                prevOnes = ones;
            }
        }

        return ans;
    }
};

int main() {

    return 0;
}