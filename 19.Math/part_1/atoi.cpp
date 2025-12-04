#include <bits/stdc++.h>
using namespace std;
#include <climits>

class Solution {
public:
    long f(string &s, int ind, long result, int sign) {
        if (ind >= s.size() || !isdigit(s[ind])) return result;
        int digit = s[ind] - '0';

        if (result > (LONG_MAX / 10) ||
            (result == LONG_MAX / 10 && digit > (INT_MAX % 10))) {
            return sign == 1 ? INT_MAX : (long)INT_MIN;
        }

        result = result * 10 + digit;
        return f(s, ind + 1, result, sign);
    }

    int myAtoi(string s) {
        int n = s.size(), ind = 0;
        while (ind < n && s[ind] == ' ') ind++;
        if (ind == n) return 0;

        int sign = 1;
        if (s[ind] == '+' || s[ind] == '-') {
            if (s[ind] == '-') sign = -1;
            ind++;
        }
        long result = f(s, ind, 0, sign);
        result *= sign;
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};


int main() {

    return 0;
}