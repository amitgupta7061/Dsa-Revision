#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GCD(int a, int b) {
        if (a == 0) return abs(b);
        return GCD(b % a, a);
    }
};

int main() {

    Solution sol;
    cout<<sol.GCD(5, 10);

    return 0;
}