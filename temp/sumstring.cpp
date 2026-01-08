#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool hasLeadingZero(string &s) {
        return s.size() > 1 && s[0] == '0';
    }
    
    bool isSumStringHelper(string &s, long long first, long long second, int ind) {
        if (ind == s.size()) return true;
    
        long long sum = first + second;
        string sumStr = to_string(sum);
    
        if (s.substr(ind, sumStr.size()) == sumStr) {
            return isSumStringHelper(s, second, sum, ind + sumStr.size());
        }
    
        return false;
    }
    
    bool isSumString(string &s) {
        int n = s.size();
        for (int len1 = 1; len1 <= n / 2; len1++) {
            string firstStr = s.substr(0, len1);
            long long first = stoll(firstStr);
            for (int len2 = 1; max(len1, len2) <= n - len1 - len2; len2++) {
                string secondStr = s.substr(len1, len2);
                if (hasLeadingZero(secondStr)) continue;
                long long second = stoll(secondStr);
                if (isSumStringHelper(s, first, second, len1 + len2)) {
                    return true;
                }
            }
        }
    
        return false;
    }

};

int main() {

    return 0;
}
