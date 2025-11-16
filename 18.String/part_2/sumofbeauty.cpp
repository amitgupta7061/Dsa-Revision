#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); ++i) {
            vector<int> count(26);
            for (int j = i; j < s.length(); ++j) {
                ++count[s[j] - 'a'];
                ans += ranges::max(count) - getMinFreq(count);
            }
        }

        return ans;
    }
    int getMinFreq(const vector<int>& count) {
        int minFreq = INT_MAX;
        for (int freq : count){
            if (freq > 0) minFreq = min(minFreq, freq);
        }
        return minFreq;
    }
};

int main() {

    return 0;
}