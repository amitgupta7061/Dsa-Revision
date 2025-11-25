#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 10 != 1 && k % 10 != 3 && k % 10 != 7 && k % 10 != 9) return -1;

        unordered_set<int> seen;
        int n = 0;

        for (int len = 1; len <= k; ++len) {
            n = (n * 10 + 1) % k;
            if (n == 0) return len;
            if (seen.contains(n)) return -1;
            seen.insert(n);
        }

        return -1;
    }
};

int main() {

    return 0;
}