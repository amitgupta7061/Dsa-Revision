#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& nums) {
        int n = nums.size();
        long long sum = (long long)n * (n + 1) / 2;
        long long squareSum = (long long)n * (n + 1) * (2LL * n + 1) / 6;
        long long gettingSum = 0, gettingSqSum = 0;
        for (int v : nums) {
            gettingSum += v;
            gettingSqSum += 1LL * v * v;
        }
        long long diff = gettingSum - sum;
        long long sqdiff = gettingSqSum - squareSum;
        long long sum_xy = sqdiff / diff;
        long long x = (diff + sum_xy) / 2;
        long long y = sum_xy - x;
        return {(int)x, (int)y};
    }
};

int main() {

    return 0;
}