#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        unordered_set<int> squared;

        for (int i = 1; i <= n; ++i) squared.insert(i * i);

        for (int a : squared)
            for (int b : squared)
                if (squared.count(a + b)) ++ans;

        return ans;
    }
};

int main() {

    return 0;
}