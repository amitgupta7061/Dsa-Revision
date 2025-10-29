#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        return (1 << bitLength(n)) - 1;
    }
    int bitLength(int n) {
        return 32 - __builtin_clz(n);
    }
};

int main() {

    return 0;
}