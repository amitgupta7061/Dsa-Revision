#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101);

        for (int num : nums) ++count[num];

        int maxFreq = ranges::max(count);
        return ranges::count(count, maxFreq) * maxFreq;
    }
};

int main() {

    return 0;
}