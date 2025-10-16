#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remcount(value, 0);
        for (int num : nums) {
            int rem = ((num % value) + value) % value;
            remcount[rem]++;
        }
        for (int i = 0; ; ++i) {
            int rem = i % value;
            if (remcount[rem] == 0) return i;
            remcount[rem]--;
        }
    }
};

int main() {

    return 0;
}