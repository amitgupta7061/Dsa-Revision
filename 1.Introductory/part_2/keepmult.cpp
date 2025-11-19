#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> have(nums.begin(), nums.end());
        while(have.count(original)){
            original *= 2;
        }
        return original;
    }
};

int main() {

    return 0;
}