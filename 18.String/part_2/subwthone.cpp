#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSub(string s) {
        long long onescnt = 0, totalcnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') onescnt++;
            else {
                totalcnt = totalcnt % MOD + (((onescnt % MOD) * (onescnt + 1) % MOD) / 2) % MOD;
                onescnt = 0;
            }
        }
        totalcnt = totalcnt % MOD + (((onescnt % MOD) * (onescnt + 1) % MOD) / 2) % MOD;
        return (int)totalcnt;
    }
};

int main() {

    return 0;
}