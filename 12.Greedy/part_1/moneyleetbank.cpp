#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7, fw = trapezoid(1, 7);
        int lfw = trapezoid(1 + weeks - 1, 7 + weeks - 1), rd = trapezoid(1 + weeks, n % 7 + weeks);
        return (fw + lfw) * weeks / 2 + rd;
    }

    int trapezoid(int a, int b) {
        return (a + b) * (b - a + 1) / 2;
    }
};

int main() {

    return 0;
}