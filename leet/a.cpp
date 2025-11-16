#include <bits/stdc++.h>
using namespace std;

#include <unordered_set>
#include <queue>
#include <algorithm>

#include <string>
#include <cmath> // You can remove this if you calculate powers iteratively

class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        long long cnt = 0, pow9 = 1;

        for (int i = 1; i < s.length(); ++i) {
            pow9 *= 9;
            cnt += pow9;
        }

        bool isok = true;
        for (int i = 0; i < s.length(); ++i) {
            int digit = s[i] - '0';

            if (digit == 0) {
                isok = false; break;
            }
            cnt += (long long)(digit - 1) * pow9;

            if (i < s.length() - 1) {
                pow9 /= 9;
            }
        }

        if (isok) cnt++;

        return cnt;
    }
};

int main() {

    return 0;
}